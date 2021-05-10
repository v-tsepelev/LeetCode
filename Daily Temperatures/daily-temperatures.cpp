class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int>& T)
  {
    std::vector<int> waitlist(T.size(), 0);
    std::stack<int> past_days;
    int i{0};
    for (auto temperature : T)
      {
	while ( (! past_days.empty()) && (T[past_days.top()] < temperature) )
	  {
	    int colder_day = past_days.top();
	    past_days.pop();
	    waitlist[colder_day] = i - colder_day;
	  }
	past_days.push(i++);
      }
    return waitlist;
  }
};

