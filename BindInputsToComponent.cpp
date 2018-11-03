void UCameraControls::BeginPlay()
{
	Super::BeginPlay();

APlayerController* PC = GetWorld()->GetFirstPlayerController();
	//Camera = GetOwner();
	//Camera->EnableInput(PController);//in case of auto-possesed camera you don't need to enable input. In other case you might need 
	PC->InputComponent->BindAxis("Forward", this, &UCameraControls::MoveForward);
	PC->InputComponent->BindAxis("Right", this, &UCameraControls::MoveRight);
	PC->InputComponent->BindAction("RollRight", IE_Pressed, this, &UCameraControls::RollRight);
	PC->InputComponent->BindAction("RollLeft", IE_Pressed, this, &UCameraControls::RollLeft);
}