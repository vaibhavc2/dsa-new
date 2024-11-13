// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// 'policy-based' data structures defined. Refer : https://goo.gl/WVDL6g
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_set_pair = tree< pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

// Driver code
int main()
{
	ordered_set<int> p;
	p.insert(5);
	p.insert(2);
	p.insert(6);
	p.insert(4);
	p.insert(4);

	// value at 3rd index in sorted array.
	cout << "The value at 3rd index :: "
		<< *(p.find_by_order(3)) << endl;

	// index of number 6
	cout << "The index of number 6 :: " << p.order_of_key(6)
		<< endl;

	// number 7 not in the set but it will show the
	// index number if it was there in sorted array.
	cout << "The index of number seven :: "
		<< p.order_of_key(7) << endl;

	return 0;
}
