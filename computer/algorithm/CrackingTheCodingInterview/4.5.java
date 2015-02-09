// method 1

public static int last = Integer.MIN_VALUE;

public static boolean checkBST(TreeNode n)
{
	if (n == null)
		return true;

	if (!checkBST(n.left))
		return false;

	// Check current
	if (n.data <= last)
		return false;

	last = n.data;

	if (!checkBST(n.right))
		return false;

	return true;
}

// method 2
int min = INT_MIN;
int max = INT_MAX;

boolean checkBST(TreeNode n, int min, int max)
{
	if (n == null)
		return true;

	if (n.data <= min || n.data > max)
		return false;

	if (!checkBST(n.left, min, n.data) || !checkBST(n.right, n.data, max))
		return false;

	return true;
}