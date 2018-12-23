FQuat AClass::AlignToNormal(UStaticMeshComponent* Mesh)
{
	FVector UpVector = FVector(0.f, 0.f, 1.f);//or get upVector. In my case it is always 0,0,1;
	FVector RotationAxis = FVector::CrossProduct(UpVector, ImpactNormal);//ImpactNormal is a Vector from Trace().FHitResult.ImpactNormal
	RotationAxis.Normalize();
	float Dot = FVector::DotProduct(UpVector, ImpactNormal);//ImpactNormal is a Vector from Trace().FHitResult.ImpactNormal
	float RAngle = acosf(Dot);
	FQuat Quat = FQuat(RotationAxis, RAngle);
	FQuat RootQuat = Mesh->GetComponentQuat();
	FQuat Rotation = Quat * RootQuat;
	return Rotation;
}