void UPathfinder::DijkstrasAlgorithm()
{
	TMap<int32, int32> Frontier; //UE doesn't have a PriorityQueue , so i am using TMap with sorting. Another way to do it is to use heaps.
	Frontier.Add(GetGridLocations().Find(Location), 10);
	CameFrom.Add(GetGridLocations().Find(Location), GetGridLocations().Find(Location));

	int32 current;
	TMap<int32, int32> cost_so_far;
	cost_so_far.Add(GetGridLocations().Find(Location), 10);

	while (Frontier.Num() != 0)
	{
		TArray<int32> temp; //temporary keys array for index access
		Frontier.GenerateKeyArray(temp);
		current = temp[temp.Num() - 1];
		Frontier.Remove(current);
		if (current == GetGridLocations().Find(Target)) { break; }//early exit

		TMap<int32, int32> graph = ArrayMerge(StringToNumbers(current, GetGridNeighbors()), StringToNumbers(current, GetMovementCost()));

		for (auto next : graph)
		{
			int32 new_cost = cost_so_far.FindRef(current) + next.Value;
			if (!cost_so_far.Contains(next.Key) || new_cost < cost_so_far.FindRef(next.Key))
			{
				cost_so_far.Add(next.Key, new_cost);
				CameFrom.Add(next.Key, current);
				Frontier.Add(next.Key, new_cost);//i had just next value here.
			}
		}
		Frontier.ValueSort(SortPredicate());//sorting with predicate
	}

}