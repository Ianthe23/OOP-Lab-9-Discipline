# Iterația 2: 
 Adăugați partea cu salvarea in fișiere pentru produse/filme/cărți, etc.<br>
 Adăugați posibilitatea de undo pentru operațiile: adaugă, șterge si modifică. 
Pentru implementare folosiți moștenire si polimorfism: <br>
• Creați o clasa abstracta ActiuneUndo care are o singura metoda: doUndo.<br>
• Creați 3 clase derivate UndoAdauga, UndoSterge, UndoModifica care in 
metoda doUndo implementează partea care reface situația de dinaintea 
adăugării/ștergerii/modificării.<br>
• In controller se v-a tine o lista de ActiuniUndo care se pot executa in orice 
moment. Se va face un apel polimorfic la metoda doUndo.<br>
• Acordați atenție gestiunii memoriei, evitați fenomenul de slicing.<br>

#
# 5. Contract de studii
## Creați o aplicație care permite:
· gestiunea unei liste de discipline. Disciplina: denumire, ore pe săptămâna, tip, cadru 
didactic <br>
· adăugare, ștergere, modificare și afișare discipline <br>
· căutare disciplina <br>
· filtrare discipline după: nr ore, cadru didactic <br>
· sortare discipline după: denumire, nr ore, cadru didactic + tip <br>
