#pragma once
class TreeNode
{
public:
	//constructors:
	TreeNode() = default;
	TreeNode(string v)
	{
		value = v;
		left = new TreeNode();
		right = new TreeNode();
	}
	//copy control: 
	TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count + 1) { }

private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};