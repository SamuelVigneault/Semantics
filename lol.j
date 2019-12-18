.source                  lol
.class                   public lol
.super                   java/lang/Object


.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 1
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   return                
.end method              

.method                  public static main([Ljava/lang/String;)V
   .limit stack          30
   .limit locals         1
   .line                 5
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   iconst_1              
   iconst_1              
   if_icmpne             LABEL0xc
   iconst_1              
   goto                  LABEL0xd
LABEL0xc:
   iconst_0              
LABEL0xd:
   iconst_1              
   if_icmpne             LABEL0x15
   iconst_1              
   goto                  LABEL0x16
LABEL0x15:
   iconst_0              
LABEL0x16:
   iconst_0              
   iconst_1              
   if_icmpne             LABEL0x23
   iconst_1              
   if_icmpne             LABEL0x28
   iconst_1              
   goto                  LABEL0x29
LABEL0x23:
   pop                   
   iconst_0              
   goto                  LABEL0x29
LABEL0x28:
   iconst_0              
LABEL0x29:
   invokevirtual         java/io/PrintStream/println(Z)V
   return                
.end method              

