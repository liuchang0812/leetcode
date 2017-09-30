/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
	for (auto& i: employees) {
	    if (i->id == id) {
		int ret = i->importance;
		for (auto j: i->subordinates) {
		    ret += getImportance(employees, j);
		}
		return ret;
	    }
	}
	return 0;
    }
};
