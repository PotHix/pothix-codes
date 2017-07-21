class Solution
  NO_SHORTEST_FOUND = -1

  def initialize(locations)
    @locations = locations
    @offered   = locations.uniq
  end

  def solve!
    shortest = NO_SHORTEST_FOUND

    for idx in 0..@locations.size-1
      for subidx in idx..@locations.size-1
        list = @locations[idx..subidx]

        if has_all_locations?(list) && should_update?(shortest, subidx - idx)
          shortest = list.size
        end
      end
    end

    shortest
  end

  private

  def has_all_locations?(hypothesis_list)
    (@offered - hypothesis_list).empty?
  end

  def should_update?(shortest, proposed_shortest)
    shortest == -1 || proposed_shortest < shortest
  end
end
