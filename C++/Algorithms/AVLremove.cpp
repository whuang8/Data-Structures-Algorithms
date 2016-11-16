// Removes one element from the dictionary
bool
AVLTree::removeElement(KeyType key){
bool found = false;
AVLNode * n = _root;
while (n) {
	 	 int cmp = strcmp(n->_key,key);
	 	 if (cmp < 0) {
	 	 n = n->_right;
	 	 } else if (cmp > 0) {
	 	 n = n->_left;
	 	 } else {
	 	 found = true;
	 	 break;
	 	 }
}
if (found) {
	 	 int side = 0;
	 	 int maxh = 0;
	 	 // find the highest child, if any
	 	 if (n->_left) {
	 	 side = 1;
	 	 	 maxh = n->_left->_height;
	 	 }
	 	 if (n->_right && n->_right->_height > maxh) {
	 	 side = 2;
	 	 }
	 	 AVLNode * c = NULL;	 	 	 	 	 // substitution node
	 	 AVLNode * fix = n->_parent;// node from which to restructure
	 	 // traverse child subtree
	 	 if (side 	= 0) {
	 	 // find leaf closest to n's key
	 	 c = (side == 1) ? n->_left : n->_right;
	 	 while ((side == 1) ? c->_right : c->_left) {
	 	 	 c = (side == 1) ? c->_right : c->_left;
	 	 }
	 	
	 	 // figure out node from which to update height
	 	 if (c->_parent 	= n) {
	 	 	 fix = c->_parent;
	 	 } else {
	 	 	 fix = c;
	 	 }
	 	
	 	 // adjust c's parent linkage
	 	 if (c->_parent) {
	 	 	 if (c->_parent->_left == c) {
	 	 	 	 c->_parent->_left = c->_right;
	 	 	 } else {
	 	 	 	 c->_parent->_right = c->_left;
	 	 	 }
	 	 }
	 	 	 c->_left = n->_left;
	 	 	 c->_right = n->_right;
	 	 	 c->_parent = n->_parent;
	 	 updateHeight(c);
	 	 }
	 	 // adjust parent linkage
	 	 if (n->_parent) {
	 	 if (n->_parent->_left == n) {
	 	 	 n->_parent->_left = c;
	 	 } else {
	 	 	 n->_parent->_right = c;
	 	 }
	 	 } else {
	 	 _root = c;
	 	 }
	 	
	 	 if (c && c->_left) {
	 	 	 c->_left->_parent = c;
	 	 }
	 	 if (c && c->_right) {
	 	 	 c->_right->_parent = c;
	 	 }
	 	 delete n;
	 	 restructure(fix);
}
return found;
}

// Update the height of an AVLNode
void
updateHeight(AVLNode * n){
int maxh = 0;
if (n->_left) {
	 	 maxh = n->_left->_height;
}
if (n->_right && maxh < n->_right->_height) {
	 	 maxh = n->_right->_height;
}
n->_height = maxh+1;
}