// Common file for tree<>
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Common operations: insert(item), size()
// Erase operation: (1) bool erase(item); (2) Iterator erase(iterator)
// Operation 1: find_by_order(k) returns an iterator to kth (counting from 0) element. (You need dereference it, like *(s.find_by_order(2))
// Operation 2: order_of_key(k) returns the number of items strictly smaller than item k.
// type_of_data, null_means_set, comparison, type_of_tree_used, support_updating_node_variants
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
