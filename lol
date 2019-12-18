class Human {
      int legs;
      int eyes;

      	  void set() {
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

void modifyHuman(Human Prof, Human Sam) {
     string sam = "Sam's turn.. What do you do?";
     string prof = "Prof's turn.. What does he do?";
     
     string kick = "kick";
     string stab = "stab";
     string nice = "be nice";
     
     int counter;
     string reader;

     string sam1 = "Yay, Sam has lot a leg due to Profe Campbell's devasting drop kick!!";

     sam = "Sam's turn.. What do you do?";
     while ( (Prof.death != true) && (Sam.death != true)) {
     	   if (counter %2 == 0) {
	   Print(sam);
	   }
	   if (counter % 2 == 1)
	   {
	   Print(prof);
	   }
	   
     
}
	if (Prof.death()) {
	Print("Sam has won, srry!");
	}
	if (Sam.death()) {
	Print("Prof Cambpell has killed Sam and saved the world!");
	}
	return;

}

int FIB( int N) {
    if (N == 1) {
        return 0;
	} 
    if (N==2) { 
        return 1;
	} 
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
	
	F = FIB(20);
	Print(F);
	
	for (F=0; F < 34; F = F +1) {
	    if (F % 2 == 0) {
	       Print(F); } }
	}
	Sam = New(Human);
	Sam.set();
	Prof = New(Human);
	Prof.set();
	
	return;
}