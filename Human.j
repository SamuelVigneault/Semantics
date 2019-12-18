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
   if_icmpeq              LABEL102 
   iconst_0
   goto                  LABEL103
LABEL102: 
   iconst_1
LABEL103:
   aload_0
   getfield              Human/legs I
   ldc                   0
   if_icmpeq              LABEL104 
   iconst_0
   goto                  LABEL105
LABEL104: 
   iconst_1
LABEL105:
   iconst_1
   if_icmpeq              LABEL106 
   iconst_1
   if_icmpeq              LABEL107
   iconst_0
   goto                  LABEL108
LABEL106: 
   pop
   iconst_1
   goto                  LABEL108
LABEL107:
   iconst_1
LABEL108:
   ireturn
   iconst_0
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

.method                  public settt()V
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

