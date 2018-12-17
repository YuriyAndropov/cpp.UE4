//simple move along the path(path is stored in an Array of vectors)
//used in TickComponent
switch (MovementStatus)
		{
		case UStatusEnum::Stop: 
		{


			if (PathArray.Contains(this->GetActorLocation()) && this->GetActorLocation() != PathArray.[PathArray.Num()-1])
			{
				SLocation = this->GetActorLocation();
				MovementStatus = UStatusEnum::Moving;
			}

		}
		case UStatusEnum::Moving:
		{
			if (this->GetActorLocation() == PahtArray[PathArray.Num()-1]) { break; }
			if (PathArray.Contains(this->GetActorLocation()))
			{
				MovementStatus = UStatusEnum::Stop;
			}
			int32 index = PathArray.Find(SLocation);
			Direction = PathArray[index + 1] - PathArray[index];
			Direction = Direction / CellSize;
			Direction = Direction * 10.f;//setting the speed
			this->SetActorLocation(this->GetActorLocation() + Direction);

		}
		}
