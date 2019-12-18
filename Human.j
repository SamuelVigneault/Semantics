.source                  lol
.class                   public Human
.super                   java/lang/Object


.field                   public eyes I

.field                   public legs I

.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 1
   aload_0
   invokespecial         java/lang/Object/<init>()V
   return
.end method

.method                  public death()Z
   .limit stack          100
   .limit locals         1
   aload_0
   getfield              Human/eyes I
   ldc                   0
   if_icmpeq              LABEL34 
   iconst_0
   goto                  LABEL35
LABEL34: 
   ldc                   1
LABEL35:
   aload_0
   getfield              Human/legs I
   ldc                   0
   if_icmpeq              LABEL36 
   iconst_0
   goto                  LABEL37
LABEL36: 
   ldc                   1
LABEL37:
   iconst_1
   if_icmpeq              LABEL38 
   iconst_1
   if_icmpeq              LABEL39
   ldc                   00 
   goto                  LABEL40
LABEL38: 
   pop
   iconst_1
   goto                  LABEL40
LABEL39:
   iconst_1
LABEL40:
   ireturn
   ldc                   00 
   ireturn
.end method

.method                  public loseEye()V
   .limit stack          100
   .limit locals         1
   aload_0
   getfield              Human/eyes I
   ldc                   1
   isub
   aload_0
   putfield              Human/eyes I
   return
.end method

.method                  public loseLeg()V
   .limit stack          100
   .limit locals         1
   aload_0
   getfield              Human/legs I
   ldc                   1
   isub
   aload_0
   putfield              Human/legs I
   return
.end method

.method                  public set()V
   .limit stack          100
   .limit locals         1
   ldc                   3
   aload_0
   putfield              Human/legs I
   ldc                   3
   aload_0
   putfield              Human/eyes I
   return
.end method

