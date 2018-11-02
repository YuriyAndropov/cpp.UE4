//line trace single channel and return bool for hit
bool UGridManager::TraceHitCheck(FVector StartPoint, FVector EndPoint)
{

	FHitResult Hit;
	return GetWorld()->LineTraceSingleByChannel(
		OUT Hit,
		StartPoint,
		EndPoint,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam);
}

//line trace single channel and return hit location
FVector UGridManager::HitLocation(FVector StartPoint, FVector EndPoint)
{
	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(
		OUT Hit,
		StartPoint,
		EndPoint,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam);
	return Hit.Location;
}

//line trace single channel and return name of phys material
FString UGridManager::HitPhysicMaterial(FVector StartPoint, FVector EndPoint)
{
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = true; // TODO test. Possible bug that will return nothing if it's false
	QueryParams.bReturnPhysicalMaterial = true;
	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(
		OUT Hit,
		StartPoint,
		EndPoint,
		ECollisionChannel::ECC_GameTraceChannel1,
		QueryParams,
		FCollisionResponseParams::DefaultResponseParam);
	UPhysicalMaterial* PhysicsMtl = Hit.PhysMaterial.Get();

	return PhysicsMtl->GetName();
}
