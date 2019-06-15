#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h> 


void my_function(int sig){ // can be called asynchronously
   printf(" You pressed ctrl+c but you can not exit shell, press ENTER to continue\n");// set flag
}
  // Register signals 
   





char *readCommand(void)//read commands from keyboard
{
  char *command = NULL;//initialize command variable which is pointer
  ssize_t buffersize = 0; // have getline allocate a buffer for us
  getline(&command, &buffersize, stdin);//read from keyboard
  return command;//return the command
}


#define bufferSize 128//initialize our buffer capacity
#define delimiters " \t\r\n\a"//delimiters for second strtok parameter


//this is a function which tokinizes the command we read from the user
//and seperates the command from the arguments
char **tokenizeCommands(char *command, int *flag)
{
  int bufsize = bufferSize, pos = 0;//initialize buffer size and the command's length
  char **letters = malloc(bufsize * sizeof(char*));//allocate memory for dynamic table letters
  char *letter;//initialize letter pointer
  

  if (!letters) {//check if memory allocated successfuly
    fprintf(stderr, "memory failure\n");//error message
    exit(EXIT_FAILURE);
  }

  letter = strtok(command, delimiters);//start tokenize procedure
  while (letter != NULL)//check if we have a letter
    {

    if(strcmp(letter, "&") != 0)//check if there is "&" in the end of our command
    {//if there is not , continue adding letters in the array
      letters[pos] = letter;
      pos++;
      *flag=0;//declare if the "&" exists, when 0 the "&" doesn't exist
    }else{
	*flag=1;//if "&" exists
    }
    
    

    if (pos >= bufsize) {//if command's letters are more that buffer's size
      bufsize += bufferSize;//then reallocate memory for buffer
      letters = realloc(letters, bufsize * sizeof(char*));//reallocate memory
      if (!letters) {//if reallocate procedure failed then print error
        fprintf(stderr, "Memory failure\n");//error message
        exit(EXIT_FAILURE);
      }
    }

    letter = strtok(NULL, delimiters);//tokenize procedure continues
  }
  letters[pos] = NULL;//initialize the array position for the next letter
  return letters;//return the array
}

//Executes fork function
int initiateCommand(char **args,int flag)
{
  pid_t pid, WaitPid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child
    if (execvp(args[0], args) == -1) {
      perror("error");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error in fork
    perror("error");
  } else {
    // Parent
  if(flag==1){
    return 1;
  }else{
    do {
      WaitPid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }
  }

  return 1;
}

int cd(char **args); //Declaration of cd built-in function
int exitFunction(char **args);//Declaration of exit built-in function


 // Array of builtin functions

char *builtinFunctions[] = 
{
  "cd",
  "exit"
};

int (*builtin_func[]) (char **) = 
{
  &cd,
  &exitFunction
};

int builtIns()
{
  return sizeof(builtinFunctions) / sizeof(char *);
}


/*Implementing built-in functions*/

int cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "Missing argument\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("Error");
    }
  }
  return 1;
}


int exitFunction(char **args)
{
  	exit(0);

	return 0;
}

//Executes user's command
int executeCommand(char **args, int flag)
{
  int k;

  if (args[0] == NULL) { //true when command is empty
    
    return 1;
  }

  for (k = 0; k < builtIns(); k++) {
    if (strcmp(args[0], builtinFunctions[k]) == 0) {
      return (*builtin_func[k])(args);
    }
  }

  return initiateCommand(args,flag);
}

//Implements the main loop of the shell
void loop(void)
{
  char *command; //user's command
  char **args; //Array of pointers each of those point in a specific tokenized word of the command
  int status; //Checks if the command is executed or not
  int flag; //Checks if an & has been typed

  do {
    printf("Type command: "); //Asks user to type command

    command = readCommand(); //Reads the command using the readCommand function

    args = tokenizeCommands(command, &flag); 

    status = executeCommand(args,flag);

    //Free allocated memory
    free(command);
    free(args);
  } while (status);
}
//Main function of the programm
int main(int argc, char **argv)
{
	signal(SIGINT, my_function);

  loop();

  return EXIT_SUCCESS;
}
