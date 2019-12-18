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

.method                  public static FIB(I)I
   .limit stack          100
   .limit locals         1
   iload_0
   ldc                   1
   if_icmpeq              LABEL22 
   iconst_0
   goto                  LABEL23
LABEL22: 
   ldc                   1
LABEL23:
   ldc                   00 
   if_icmpeq             LABEL21 
   ldc                   0
   ireturn
LABEL21: 
   iload_0
   ldc                   2
   if_icmpeq              LABEL25 
   iconst_0
   goto                  LABEL26
LABEL25: 
   ldc                   1
LABEL26:
   ldc                   00 
   if_icmpeq             LABEL24 
   ldc                   1
   ireturn
LABEL24: 
   iload_0
   ldc                   1
   isub
   invokestatic          _lol/FIB(I)I
   iload_0
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
   aload_1
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   ldc                   20
   invokestatic          _lol/FIB(I)I
   istore                2
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iload_2
   invokevirtual         java/io/PrintStream/println(I)V
   ldc                   0
   istore                2
LABEL27: 
   iload_2
   ldc                   34
   if_icmplt              LABEL29
   iconst_0
   goto                  LABEL30
LABEL29: 
   iconst_1
LABEL30:
   iconst_0
   if_icmpeq             LABEL28
   iload_2
   ldc                   2
   irem
   ldc                   0
   if_icmpeq              LABEL32 
   iconst_0
   goto                  LABEL33
LABEL32: 
   ldc                   1
LABEL33:
   ldc                   00 
   if_icmpeq             LABEL31 
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iload_2
   invokevirtual         java/io/PrintStream/println(I)V
LABEL31: 
   iload_2
   ldc                   1
   iadd
   istore                2
   goto                  LABEL27 
LABEL28:
   return
.end method

.method                  public static modifyHuman(LHuman;LHuman;)V
   .limit stack          100
   .limit locals         2
   return
.end method

