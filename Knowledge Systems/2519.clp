;Emmanouil Gionanidis, AEM: 2519
;Γιονανίδης Εμμανουηλ, ΑΕΜ: 2519


;φτιάχνω μια συνάρτηση για την εμγφάνιση των ερωτήσεων προς τον χρήστη και την ακριβή καθοδήγησή του όσον αφορά της απαντήσεις
;που πρέπει να δώσει
;Αναλυτικά πρώτα γίνεται η ερώτηση 'printout'
;μετά το σύστημα διαβάζει την απάντηση 'read/readline' 
;και τέλος την εισάγει σαν γεγονός με τη χρήση του 'assert' 
;δίνοντας τιμές στις μεταβλητές σύμφωνα με αυτά που πληκτρολόγησε ο χρήστης.


(deffunction ask-question ()
   
   (printout t "Theleis mikro, mesaio h' megalo spiti?" crlf)
   (bind ?megethosSpitiou (readline))
   (assert (megethosSpitiou ?megethosSpitiou))
   
   (printout t "Se poia perioxi (anatolika/kentro/dytika)?" crlf)
   (bind ?perioxi (read))
   (assert (perioxi ?perioxi))
   
   (printout t "Kainourio h' palio spiti (kainourio/palio)?" crlf)
   (bind ?kp (read))
   (assert (kp ?kp))
   
   (printout t "Polykatoikia h' mezoneta (polykatoikia/mezoneta)?" crlf)
   (bind ?pm(read))
   (assert (pm ?pm))
   
   (printout t "Posa melh exei i oikogeneia?" crlf)
   (bind ?melhOikogeneias (read))
   (assert (melhOikogeneias ?melhOikogeneias))
   
   (printout t "Exeis amaksi (nai/oxi)?" crlf)
   (bind ?amaksi (read))
   (assert (amaksi ?amaksi))
   
   
   )

;----------------  
   
;στον κανόνα αρχικοποιώ όλο τα γεγονότα, πιο συγκεκριμένα όλα τα σπίτια ως γεγονότα όπως ζητήθηκε, αλλά και αντιστοιχώ κάθε
;συνοικία στην περιοχή την οποία ανήκει για να με βοηθήσει στους ελέγχους για την επιλογή σπιτιού.
;Όσον αφορά το γεγονός Spiti αυτό έχει την εξής μορφή
;Σπίτι κωδικός(ID) εμβαδόν αριθμός δωματίων παλιό/καινούργιο πολυκατοικία/μεζονέτα (εαν υπάρχει parking) περιοχή τιμή 
;με την παραπάνω σειρά όπως μας δίνονται στον πίνακα
;ενώ για το γεγονός συνοικία έχω την μορφή sinoikia OnomaSinoikias Perioxh.

   (defrule init "eisagwgikes erwtiseis"
    (initial-fact)
    =>
    (printout t crlf crlf crlf
    "Kalosirthate sto programma euresis spitiou" crlf
     crlf
    )
    
    (ask-question  )
 
    (printout t crlf)
     (assert(spiti  1 95 3 palio polykatoikia oxi Kalamaria 190000))
    
     (assert(spiti 2 105 2 palio mezoneta nai Pylaia 189000))
    
     (assert(spiti 3 111 3 kainourio polykatoikia nai Toumpa 177600))
    
     (assert(spiti 4 84 2 palio polykatoikia oxi AnwPoli 142800))
    
     (assert(spiti 5 97 2 kainourio mezoneta oxi AgiosPaulos 145500))
 
     (assert(spiti 6 93 2 kainourio polykatoikia oxi Sykies 120900))

     (assert(spiti 7 120 3 kainourio mezoneta oxi Stauroupoli 144000))
    
     (assert(spiti 8 130 4 kainourio polykatoikia nai Euosmos 130000))
    
     (assert(spiti 9 92 2 palio polykatoikia oxi Menemeni 128800))
    
     (assert(spiti 10 115 3 kainourio polykatoikia nai Pylaia 210000))
     
     (assert(sinoikia Pylaia anatolika))
     (assert(sinoikia Kalamaria anatolika))
     (assert(sinoikia Toumpa anatolika))
     
     (assert(sinoikia AnwPoli kentro))
     (assert(sinoikia AgiosPaulos kentro))
     (assert(sinoikia Sykies kentro))
     
     (assert(sinoikia Stauroupoli dytika))
     (assert(sinoikia Euosmos dytika))
     (assert(sinoikia Menemeni dytika))
   
    )
    
;σε αυτό το σημείο ορίστηκε ο κανόνας ο οποίος ενεργοποιείται όταν ο χρήστης εισάγει στο πεδίο megethosSpitiou την τιμή 'mikro'
;όπου γίνεται έλεγχος για το ποιά σπίτια είναι μικρά, είναι η μόνη συνθήκη που διαχωρίζει τα σπίτια σε μικρό/μεγάλο/μεσαίο. Από όλους
;τους ελέγχους ο μόνος που αλλάζει κάθε φορά είναι αυτός για το μέγεθος οπότε οι υπόλοιποι δεν χρειάζεται να σχολιαστούν ξανά.    
    
    (defrule check-house-mikro "elegxos spitiou"
     (megethosSpitiou "mikro")
     (perioxi ?perioxi)
     (kp ?kp)
     (pm ?pm)
     (melhOikogeneias ?melhOikogeneias)
     (amaksi ?amaksi)
     
     (spiti ?id ?e ?n ?kp1 ?pm1 ?p ?s ?t)
;συνθήκη για το εαν η συνοικία που είναι το σπίτι βρίσκεται στην περιοχή που ζήτησε ο χρήστης
     (sinoikia ?s ?perioxi)
;συνθήκη για το εαν ο χρήστης απάντησε 'ναι' στην ερώτηση αμα έχει αμάξι και το πεδίο της ύπαρξης parking στον κανόνα σπίτι είναι και
;αυτό ναι, δηλαδή το σπίτι τηρεί αυτή την προυπόθεση
     (test(member ?amaksi (create$ ?p)))
;έλεγχος για το εαν η προτίμηση του χρήση σε καινούργιο/παλιό συμπίπτουν με το συγκεκριμένο σπίτι που ελέγχει
     (test(member ?kp(create$ ?kp1)))
;έλεγχος για το εαν το σπίτι συμπίτει στην προτίμηση του χρήστη πολυκατοικία/μεζονέτα
     (test(member ?pm(create$ ?pm1)))
;έλεγχος για το εαν ένα σπίτι είναι μικρό, διαιρόντας το εμβαδόν του με τον αριθμό μελών της οικογένειας, ένα σπίτι είναι μικρό
;εαν σε κάθε άτομο αντιστοιχόυν λιγότερα απο 25 m^2
     (test (< (/ ?e ?melhOikogeneias) 25))
;απαραίτητη προυπόθεση για να μπορεί να προταθεί ένα σπίτι με βάση τις απαιτήσεις του χρήστη είναι ο έλεγχος για τον αριθμό των δωματίων
;βάσει τα μέλη της οικογενείας. Ο αριθμός των δωματίων πρέπει να είναι μεγαλύτερος απο (αριθμός μελών οικογενείας)/2 ωστέ να μπορούν να 
;μείνουν το μέγιστο 2 άτομα σε ένα δωμάτιο αλλα και μικρότερος απο (αριθμός μελών οικογενέιας)-1 όπως ζητείται.
     (test (and (> ?n (/ ?melhOikogeneias 2)) (<= ?n (- ?melhOikogeneias 1))))
     
    =>
    (assert (LYSI ?id))
    
    )
    
    
    (defrule check-house-mesaio "elegxos spitiou"
     (megethosSpitiou "mesaio")
     (perioxi ?perioxi)
     (kp ?kp)
     (pm ?pm)
     (melhOikogeneias ?melhOikogeneias)
     (amaksi ?amaksi)
     
     (spiti ?id ?e ?n ?kp1 ?pm1 ?p ?s ?t)
     (sinoikia ?s ?perioxi)
     (test(member ?amaksi (create$ ?p)))
     (test(member ?kp(create$ ?kp1)))
     (test(member ?pm(create$ ?pm1)))
;για το μεσαίο σπίτι αλλάζει μόνο ο έλεγχος στα τετραγωνικά μέτρα ανα άτομα τα οποία πρέπει να είναι στο διάστημα [25,35]
     (test (and(>= (/ ?e ?melhOikogeneias) 25) (<= (/ ?e ?melhOikogeneias) 35)))
     (test (and (> ?n (/ ?melhOikogeneias 2)) (<= ?n (- ?melhOikogeneias 1))))
    
    =>
    
     (assert (LYSI ?id))
    )
    
    (defrule check-house-megalo "elegxos spitiou"
     
     (megethosSpitiou "megalo")
     (perioxi ?perioxi)
     (kp ?kp)
     (pm ?pm)
     (melhOikogeneias ?melhOikogeneias)
     (amaksi ?amaksi)
     
     (spiti ?id ?e ?n ?kp1 ?pm1 ?p ?s ?t)
     (sinoikia ?s ?perioxi)
     (test(member ?amaksi (create$ ?p)))
     (test(member ?kp(create$ ?kp1)))
     (test(member ?pm(create$ ?pm1)))
;για το μεγάλο σπίτι πάλι αλλάζει μόνο ο έλεγχος για τα τετραγωνικά μέτρα ανα άτομο τα οποία πρέπει να είναι παραπάνω απο 25
     (test (> (/ ?e ?melhOikogeneias) 35) )
     (test (and (> ?n (/ ?melhOikogeneias 2)) (<= ?n (- ?melhOikogeneias 1))))
    
    =>
    
     (assert(LYSI ?id))
    )
    
    
    
    (defrule announce-solution "yparxei lysi"
      (declare (salience -1))
      (LYSI ?id)
      (spiti ?id ?e ?n ?kp1 ?pm1 ?p ?s ?t)
    =>
;εαν υπάρχει/υπάρχουν γεγονότα λύση, δηλαδή σπίτια που τηρούν τις προδιαγραφές τα εμφανίζουμε στον χρήστη. Οι κανόνες για τον έλεγχο άμα
;υπάρχει λύση έχουνε μικρότερη προταραιότητα απο τους παραπάνω γιατί πρέπει να εκτελεστούν όταν έχουν ελεγχθεί όλα τα σπίτια.   
    (printout t "Ena katallilo spiti gia sena einai to no " ?id crlf)
    (printout t "    Embado: " ?e crlf)
    (printout t "    Domatia: " ?n crlf)
    (printout t "    Hlikia: " ?kp1 crlf)
    (printout t "    Typos: " ?pm1 crlf)
    (printout t "    Parking: " ?p crlf)
    (printout t "    Synoikia: " ?s crlf)
    (printout t "    Timh: " ?t crlf)
    
    )
    
    (defrule no-solution "den yparxei lysi" 
     (declare (salience -1))
     (not(LYSI ?lysi))
    =>
;ελέγχουμε εαν δεν έχει εισαγχθεί γεγονός λύση, αυτό σημαίνει ότι δεν υπάρχει, οπότε βγάζουμε κατάλληλο μήνυμα.
    (printout t "Den yparxei spiti pou na symfwnei me tis prodiagrafes." crlf)
    )
    
    
    
