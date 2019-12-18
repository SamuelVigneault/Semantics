.source                  test.java
.class                   public test
.super                   java/lang/Object

.field                   protected lol Z
.field                   public static lol1 Z
.field                   public static lol2 Ltest;
.field                   public static lol4 Ljava/lang/String;

.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 5
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   return                
.end method              

.method                  public static main([Ljava/lang/String;)V
   .limit stack          2
   .limit locals         1
   .line                 9
   getstatic             test/lol1 Z
   ifeq                  LABEL0x11
   .line                 10
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "Hello, World"
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   goto                  LABEL0x19
   .line                 11
LABEL0x11:
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "Bye, World"
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   .line                 12
LABEL0x19:
   return                
.end method              

.method                  public main1([Ljava/lang/String;)V
   .limit stack          5
   .limit locals         10
   .line                 14
   new                   lolipop
   dup                   
   invokespecial         lolipop/<init>()V
   astore_2              
   .line                 15
   aload_2               
   invokevirtual         lolipop/juul()V
   .line                 21
   new                   java/util/Scanner
   dup                   
   getstatic             java/lang/System/in Ljava/io/InputStream;
   invokespecial         java/util/Scanner/<init>(Ljava/io/InputStream;)V
   astore                7
   .line                 22
   aload                 7
   invokevirtual         java/util/Scanner/nextInt()I
   istore_3              
   .line                 23
   bipush                10
   bipush                10
   multianewarray        [[J 2
   astore                4
   .line                 24
   new                   java/io/BufferedReader
   dup                   
   new                   java/io/InputStreamReader
   dup                   
   getstatic             java/lang/System/in Ljava/io/InputStream;
   invokespecial         java/io/InputStreamReader/<init>(Ljava/io/InputStream;)V
   invokespecial         java/io/BufferedReader/<init>(Ljava/io/Reader;)V
   astore                8
   .line                 26
LABEL0x3b:
   aload                 8
   invokevirtual         java/io/BufferedReader/readLine()Ljava/lang/String;
   astore                9
   .line                 30
LABEL0x42:
   goto                  LABEL0x4c
   .line                 28
LABEL0x45:
   astore                9
   .line                 29
   aload                 9
   invokevirtual         java/io/IOException/printStackTrace()V
   .line                 31
LABEL0x4c:
   aload_0               
   iconst_1              
   putfield              test/lol Z
   .line                 32
   aload_0               
   getfield              test/lol Z
   istore                5
   .line                 33
   ldc                   "1"
   astore                6
   .line                 34
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iconst_1              
   aload_0               
   getfield              test/lol Z
   if_icmpne             LABEL0x6a
   iconst_1              
   goto                  LABEL0x6b
LABEL0x6a:
   iconst_0              
LABEL0x6b:
   invokevirtual         java/io/PrintStream/println(Z)V
   .line                 37
   return                
   .catch                java/io/IOException from LABEL0x3b to LABEL0x42 using LABEL0x45
.end method              

