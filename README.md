# Iterația 2: 
 Adăugați partea cu salvarea in fișiere pentru produse/filme/cărți, etc.
 
 Adăugați posibilitatea de undo pentru operațiile: adaugă, șterge si modifică. 
Pentru implementare folosiți moștenire si polimorfism: 

• Creați o clasa abstracta ActiuneUndo care are o singura metoda: doUndo.

• Creați 3 clase derivate UndoAdauga, UndoSterge, UndoModifica care in 
metoda doUndo implementează partea care reface situația de dinaintea 
adăugării/ștergerii/modificării.

• In controller se v-a tine o lista de ActiuniUndo care se pot executa in orice 
moment. Se va face un apel polimorfic la metoda doUndo.

• Acordați atenție gestiunii memoriei, evitați fenomenul de slicing.

#
# 5. Contract de studii
## Creați o aplicație care permite:
· gestiunea unei liste de discipline. Disciplina: denumire, ore pe săptămâna, tip, cadru 
didactic

· adăugare, ștergere, modificare și afișare discipline

· căutare disciplina

· filtrare discipline după: nr ore, cadru didactic

· sortare discipline după: denumire, nr ore, cadru didactic + tip
