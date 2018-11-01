void UPathfinder::BreadthFirstSearch()
{
	TQueue<int32> Frontier;
	Frontier.Enqueue(GetGridLocations().Find(Location));
	CameFrom.Add(GetGridLocations().Find(Location), GetGridLocations().Find(Location));
	int32 current;
	int32& OutItem = current;
	Frontier.Peek(OutItem);
	while (!Frontier.IsEmpty())
	{
		Frontier.Peek(OutItem);
		Frontier.Pop();
		TArray<int32> nb = StringToNumbers(current, GetGridNeighbors());
		for (int32 next : nb)
		{
			if (!CameFrom.Contains(next))
			{
				Frontier.Enqueue(next);
				CameFrom.Add(next, current);
			}
		}
		if (current == GetGridLocations().Find(Target)) { break; } //early exit
	}
}
