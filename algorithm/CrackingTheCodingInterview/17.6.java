int findEndOfLeftSubsequence(int[] array)
{
	for (int i = 1; i < array.length; i++)
	{
		if (array[i] < array[i -1]) return i -1;
	}
	return array.length - 1;
}

int findStartOfRightSubsequence(int[] array)
{
	for (int i = array.length-2; i>=0;i--)
	{
		if (array[i] > array[i +1]) return i +1;
	}
	return 0;
}

int shrinkLeft(int[] array, int min_index, int start)
{
	int comp = array[min_index];
	for (int i = start - 1; i >= 0; i--)
	{
		if (array[i] <= comp) return i+1;
	}
	return 0;
}

int shrinkRight(int[] array, int max_index, int start)
{
	int comp = array[max_index];
	for (int i = start; i < array.length; i++)
	{
		if (array[i] >= comp) return i-1;
	}
	return array.length - 1;
}

void findUnsortedSequence(int[] array)
{
	int end_left = findEndOfLeftSubsequence(array);

	int start_right = findStartOfRightSubsequence(array);

	int min_index = end_left + 1;
	if (min_index >= array.length) return; // Already sorted

	int max_index = start_right - 1;
	for (int i = end; i <= start_right; i++) 
	{
		if (array[i] < array[min_index]) {
			min_index = i;
		}
		if (array[i] > array[max_index]) {
			max_index = i;
		}
	}

	int left_index - shrinkLeft(array, min_index, end_left);
	int right_index = shrinkRight(array, max_index, start_right);

	System.out.println(left_index + " " + right_index);
}
