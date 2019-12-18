.source                  lol
.class                   public _lol
.super                   java/lang/Object


.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 1
   aload_0
   invokespecial         java/lang/Object/<init>()V
   return
.end method

.method                  public static Battle(LHuman;LHuman;)V
   .limit stack          100
   .limit locals         15
   ldc                   "Sam's turn.. What do you do?"
   astore                2
   ldc                   "Prof's turn.. What does he do?"
   astore                3
   ldc                   "kick"
   astore                4
   ldc                   "stab"
   astore                5
   ldc                   "be nice"
   astore                6
   ldc                   0
   istore                7
   ldc                   "Yay, Sam has lot a leg due to Profe Campbell's devasting drop kick!!"
   astore                9
   ldc                   "Sam took a knife to the eye and lost an eye :) !!"
   astore                10
   ldc                   "Unfortunately, Sam gets no damage from el Profe."
   astore                11
   ldc                   "Sam break Campbell's leg, oh no!"
   astore                12
   ldc                   "Sam stabs Campbell, who loses an eye and can't teach Compilers anymore. Srry not srry Frosh."
   astore                13
   ldc                   "Campbell comes out of this round untouched, thank God for his compiler"
   astore                14
LABEL21: 
   aload 0
   invokevirtual         Human/death()Z
   iconst_1
   if_icmpeq              LABEL23 
   iconst_1
   goto                  LABEL24
LABEL23: 
   ldc                   0
LABEL24:
   aload 1
   invokevirtual         Human/death()Z
   iconst_1
   if_icmpeq              LABEL25 
   iconst_1
   goto                  LABEL26
LABEL25: 
   ldc                   0
LABEL26:
   iconst_0
   if_icmpeq              LABEL27 
   iconst_0
   if_icmpeq              LABEL28
   iconst_1
   goto                  LABEL29
LABEL27: 
   pop
   iconst_0
   goto                  LABEL29
LABEL28:
   iconst_0
LABEL29:
   iconst_0
   if_icmpeq             LABEL22
   iload 7
   ldc                   2
   irem
   ldc                   1
   if_icmpeq              LABEL31 
   iconst_1
   goto                  LABEL32
LABEL31: 
   ldc                   0
LABEL32:
   iconst_0
   if_icmpeq             LABEL30 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 2
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL30: 
   iload 7
   ldc                   2
   irem
   ldc                   1
   if_icmpeq              LABEL34 
   iconst_0
   goto                  LABEL35
LABEL34: 
   iconst_1
LABEL35:
   iconst_0
   if_icmpeq             LABEL33 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 3
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL33: 
   new                   java/io/BufferedReader
   dup
   new                   java/io/InputStreamReader
   dup
   getstatic             java/lang/System/in Ljava/io/InputStream;
   invokespecial         java/io/InputStreamReader/<init>(Ljava/io/InputStream;)V
   invokespecial         java/io/BufferedReader/<init>(Ljava/io/Reader;)V
   astore                8
   aload 8
   aload 4
   if_acmpeq              LABEL37 
   iconst_0
   goto                  LABEL38
LABEL37: 
   iconst_1
LABEL38:
   iload 7
   ldc                   2
   irem
   ldc                   0
   if_icmpeq              LABEL39 
   iconst_0
   goto                  LABEL40
LABEL39: 
   iconst_1
LABEL40:
   iconst_0
   if_icmpeq              LABEL41 
   iconst_0
   if_icmpeq              LABEL42
   iconst_1
   goto                  LABEL43
LABEL41: 
   pop
   iconst_0
   goto                  LABEL43
LABEL42:
   iconst_0
LABEL43:
   iconst_0
   if_icmpeq             LABEL36 
   aload 0
   invokevirtual         Human/loseLeg()V
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 12
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL36: 
   aload 8
   aload 5
   if_acmpeq              LABEL45 
   iconst_0
   goto                  LABEL46
LABEL45: 
   iconst_1
LABEL46:
   iload 7
   ldc                   2
   irem
   ldc                   0
   if_icmpeq              LABEL47 
   iconst_0
   goto                  LABEL48
LABEL47: 
   iconst_1
LABEL48:
   iconst_0
   if_icmpeq              LABEL49 
   iconst_0
   if_icmpeq              LABEL50
   iconst_1
   goto                  LABEL51
LABEL49: 
   pop
   iconst_0
   goto                  LABEL51
LABEL50:
   iconst_0
LABEL51:
   iconst_0
   if_icmpeq             LABEL44 
   aload 0
   invokevirtual         Human/loseEye()V
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 13
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL44: 
   aload 8
   aload 6
   if_acmpeq              LABEL53 
   iconst_0
   goto                  LABEL54
LABEL53: 
   iconst_1
LABEL54:
   iload 7
   ldc                   2
   irem
   ldc                   0
   if_icmpeq              LABEL55 
   iconst_0
   goto                  LABEL56
LABEL55: 
   iconst_1
LABEL56:
   iconst_0
   if_icmpeq              LABEL57 
   iconst_0
   if_icmpeq              LABEL58
   iconst_1
   goto                  LABEL59
LABEL57: 
   pop
   iconst_0
   goto                  LABEL59
LABEL58:
   iconst_0
LABEL59:
   iconst_0
   if_icmpeq             LABEL52 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 14
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL52: 
   aload 8
   aload 4
   if_acmpeq              LABEL61 
   iconst_0
   goto                  LABEL62
LABEL61: 
   iconst_1
LABEL62:
   iload 7
   ldc                   2
   irem
   ldc                   1
   if_icmpeq              LABEL63 
   iconst_0
   goto                  LABEL64
LABEL63: 
   iconst_1
LABEL64:
   iconst_0
   if_icmpeq              LABEL65 
   iconst_0
   if_icmpeq              LABEL66
   iconst_1
   goto                  LABEL67
LABEL65: 
   pop
   iconst_0
   goto                  LABEL67
LABEL66:
   iconst_0
LABEL67:
   iconst_0
   if_icmpeq             LABEL60 
   aload 1
   invokevirtual         Human/loseLeg()V
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 9
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL60: 
   aload 8
   aload 5
   if_acmpeq              LABEL69 
   iconst_0
   goto                  LABEL70
LABEL69: 
   iconst_1
LABEL70:
   iload 7
   ldc                   2
   irem
   ldc                   1
   if_icmpeq              LABEL71 
   iconst_0
   goto                  LABEL72
LABEL71: 
   iconst_1
LABEL72:
   iconst_0
   if_icmpeq              LABEL73 
   iconst_0
   if_icmpeq              LABEL74
   iconst_1
   goto                  LABEL75
LABEL73: 
   pop
   iconst_0
   goto                  LABEL75
LABEL74:
   iconst_0
LABEL75:
   iconst_0
   if_icmpeq             LABEL68 
   aload 1
   invokevirtual         Human/loseEye()V
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 10
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL68: 
   aload 8
   aload 6
   if_acmpeq              LABEL77 
   iconst_0
   goto                  LABEL78
LABEL77: 
   iconst_1
LABEL78:
   iload 7
   ldc                   2
   irem
   ldc                   1
   if_icmpeq              LABEL79 
   iconst_0
   goto                  LABEL80
LABEL79: 
   iconst_1
LABEL80:
   iconst_0
   if_icmpeq              LABEL81 
   iconst_0
   if_icmpeq              LABEL82
   iconst_1
   goto                  LABEL83
LABEL81: 
   pop
   iconst_0
   goto                  LABEL83
LABEL82:
   iconst_0
LABEL83:
   iconst_0
   if_icmpeq             LABEL76 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 11
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL76: 
   iload 7
   ldc                   1
   iadd
   istore                7
   goto                  LABEL21 
LABEL22:
   aload 0
   invokevirtual         Human/death()Z
   iconst_0
   if_icmpeq             LABEL84 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "Sam has won, srry!"
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL84: 
   aload 1
   invokevirtual         Human/death()Z
   iconst_0
   if_icmpeq             LABEL85 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "Prof Cambpell has killed Sam and saved the world!"
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
LABEL85: 
   return
   return
.end method

.method                  public static FIB(I)I
   .limit stack          100
   .limit locals         1
   iload 0
   ldc                   0
   if_icmpeq              LABEL87 
   iconst_0
   goto                  LABEL88
LABEL87: 
   iconst_1
LABEL88:
   iconst_0
   if_icmpeq             LABEL86 
   ldc                   0
   ireturn
LABEL86: 
   iload 0
   ldc                   1
   if_icmpeq              LABEL90 
   iconst_0
   goto                  LABEL91
LABEL90: 
   iconst_1
LABEL91:
   iconst_0
   if_icmpeq             LABEL89 
   ldc                   0
   ireturn
LABEL89: 
   iload 0
   ldc                   2
   if_icmpeq              LABEL93 
   iconst_0
   goto                  LABEL94
LABEL93: 
   iconst_1
LABEL94:
   iconst_0
   if_icmpeq             LABEL92 
   ldc                   1
   ireturn
LABEL92: 
   iload 0
   ldc                   1
   isub
   invokestatic          _lol/FIB(I)I
   iload 0
   ldc                   2
   isub
   invokestatic          _lol/FIB(I)I
   iadd
   ireturn
   ldc                   00 
   ireturn
.end method

.method                  public static main([Ljava/lang/String;)V
   .limit stack          100
   .limit locals         5
   ldc                   "Hey fellow compilers!"
   astore                1
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload 1
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   ldc                   0
   istore                2
LABEL95: 
   iload 2
   ldc                   34
   if_icmplt              LABEL97
   iconst_0
   goto                  LABEL98
LABEL97: 
   iconst_1
LABEL98:
   iconst_0
   if_icmpeq             LABEL96
   iload 2
   ldc                   2
   irem
   ldc                   0
   if_icmpeq              LABEL100 
   iconst_0
   goto                  LABEL101
LABEL100: 
   iconst_1
LABEL101:
   iconst_0
   if_icmpeq             LABEL99 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iload 2
   invokevirtual         java/io/PrintStream/println(I)V
LABEL99: 
   iload 2
   ldc                   1
   iadd
   istore                2
   goto                  LABEL95 
LABEL96:
   ldc                   20
   invokestatic          _lol/FIB(I)I
   istore                2
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iload 2
   invokevirtual         java/io/PrintStream/println(I)V
   return
   return
.end method

