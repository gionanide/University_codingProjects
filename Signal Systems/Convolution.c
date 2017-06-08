#include <stdio.h>
#include <stdlib.h>

//convolution function
float *conv(float *Aarray,float *Barray,int lengthA,int lengthB);

int main()
{
    FILE *fsignal;
    fsignal = fopen("signal.txt","r");//open signal file
    if(fsignal == NULL){
        printf("Can not open the file");//ERROR
        return -1;
    }
    float ch;
    int count=0;//number of elements
    while(1){//count elements of file
        fscanf(fsignal, "%f" ,&ch);
        if(feof(fsignal)){
            break;
        }
        ++count;
    }


    //opne the response file
    FILE *fresponse;
    fresponse = fopen("response.txt","r");
    if(fresponse == NULL){
        printf("Can not open the file");//ERROR
        return -1;
    }
    float ch1;
    int count1=0;//number of elements
    while(1){//count elements of file
        fscanf(fresponse, "%f" ,&ch1);
        if(feof(fresponse)){
            break;
        }
        ++count1;
    }


    //make the arrays of signal and response
    float *signal,*response;

    signal = (float *)malloc(count + 1);//and the size of them is the number of elements i count before
    if (signal == NULL){
        printf("malloc failed");//TEST
        return -1;
    }
    response = (float *)malloc(count1 + 1);
    if (response == NULL){
        printf("malloc failed");//TEST
        return -1;
    }

    rewind(fsignal);//take the cercor in the end of the file in order to read it again
    float ch2;
    int k =0;
    printf("Signal file's elements are:\n");
    while(1){//count elements of file
        fscanf(fsignal, "%f" ,&ch2);
        signal[k] = ch2;//take the lements of the file into an array
        printf("%f\n",signal[k]);//print the array
        if(feof(fsignal)){//TEST
            break;
        }
        k++;
    }

    //the same procedure like the signal file
    rewind(fresponse);
    float ch3;
    int l =0;
    printf("Response file's elements are:\n");
    while(1){//count elements of file
        fscanf(fresponse, "%f" ,&ch3);
        response[l] = ch3;
        printf("%f\n",response[l]);
        if(feof(fresponse)){
            break;
        }
        l++;
    }
    //for the last action i call the convolution function
    float *convolution;
    convolution = (float *)malloc(count + count1 + 1);
    if (convolution == NULL){//TEST
        printf("malloc failed");
        return -1;
    }
    convolution = conv(signal,response,count,count1);
    int p;

    FILE *fp8;//initialize a new txt in order to wirte the convolution numbers
    fp8 = fopen("projectfile.txt","w");//open the file to write
    if(fp8 == NULL){//check the null pointer
        printf("Can not open the file");
        return -1;
    }

    printf("Convolution array is:\n");
    for(p=0;p<count + count1 + 1;p++){
        printf("%f\n",convolution[p]);//print the convolution numbers
        fprintf(fp8 , "%f\n", convolution[p]);//and the write them into the file
    }


}

float *conv(float *Aarray,float *Barray,int lengthA,int lengthB){
    int size;
    int i,j,i1;
    float temp;
    float *C;

    //initialize convolution array
    size = lengthA + lengthB + 1;
    C = (float *)malloc(size);
    if (C == NULL){//TEST
        printf("malloc failed");
        return -1;
    }
    //begin the process of convolution
    for(i=0;i<size;i++){
        i1 = i;
        temp = 0.0;
        for(j=0;j<lengthB + 1;j++){
            if(i1>=0 && i1<lengthA + 1){
                temp = temp + (Aarray[i1]*Barray[j]);
            }
            i1 = i1 - 1;
            C[i] = temp;
        }
    }
    return(C);
}

