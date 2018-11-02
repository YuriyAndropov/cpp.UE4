//return array of ints from string divided by commas
TArray<int32> UPathfinder::StringToNumbers(int32 index, TArray<FString> StringsArray)
{
	TArray<int32> result;
	FString number;
	FString line = StringsArray[index];
	for (char w : line)
	{
		if (w != ',') { number.AppendChar(w); }
		else { result.Push(FCString::Atoi(*number)); number.Empty(); }
	}
	return result;
}
