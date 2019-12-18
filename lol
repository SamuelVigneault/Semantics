class Human {
      int legs;
      int eyes;

      	  void settt() {
      	       legs = 3;
	       eyes = 3;
	  }

	  void loseEye() {
	       eyes = eyes - 1;
	  }

	  void loseLeg() {
	       legs = legs - 1;
	  }

	  bool death() {
	       return (eyes == 0) || (legs == 0);
	  }
	  
}

void Battle(Human Prof, Human Sam) {
     string sam;
     string prof;
     
     string kick;
     string stab;
     string nice;
     
     int counter;
     string reader;

     string sam1; string sam2; string sam3;
     string prof1; string prof2; string prof3;

     sam = "Sam's turn.. What do you do?";
     prof = "Prof's turn.. What does he do?";
     
     kick = "kick";
     stab = "stab";
     nice = "be nice";
     
     counter = 0;

     sam1 = "Yay, Sam has lot a leg due to Profe Campbell's devasting drop kick!!";
     sam2 = "Sam took a knife to the eye and lost an eye :) !!"; 
     sam3 = "Unfortunately, Sam gets no damage from el Profe.";
     prof1 = "Sam break Campbell's leg, oh no!"; 
     prof2 = "Sam stabs Campbell, who loses an eye and can't teach Compilers anymore. Srry not srry Frosh.";
     prof3 = "Campbell comes out of this round untouched, thank God for his compiler";
     
     while ( (Prof.death() != true) && (Sam.death() != true)) {
     	   if (counter % 2 != 1) {
	   Print(sam);
	   }
	   if (counter % 2 == 1)
	   {
	   Print(prof);
	   }
	   reader = ReadLine();
	   if (reader == kick && counter %2 == 0) { 
	   Prof.loseLeg();
	   Print(prof1); }
	   if (reader == stab && counter %2 == 0) { 
	   Prof.loseEye();
	   Print(prof2); }
	   if (reader == nice && counter %2 == 0) { 
	   Print(prof3); }
	   if (reader == kick && counter %2 == 1) { 
	   Sam.loseLeg();
	   Print(sam1); }
	   if (reader == stab && counter %2 == 1) {
	   Sam.loseEye();
	   Print(sam2); }
	   if (reader == nice && counter %2 == 1) { Print(sam3); }
	   counter = counter + 1;
     }
	if (Prof.death()) { Print("Sam has won, srry!"); }
	if (Sam.death()) { Print("Prof Cambpell has killed Sam and saved the world!"); }
	return;

}

int FIB(int N) {
    if (N == 0) { return 0; }
    if (N == 1) { return 0; } 
    if (N == 2) { return 1; } 
    return FIB(N-1)+FIB(N-2);
}


void main(string[] lol)
{
	string welcome;
	int F;
	Human Sam;
	Human Prof;
	welcome = "Hey fellow compilers!";
	Print(welcome);
	
	F=0;
	for (; F < 34; F = F + 1) {
	    if (F % 2 == 0) {
	    Print(F);
	   }
	 }
	
	F = FIB(20);
	Print(F);
	return;
}