package wdx.java.study;

public class ArrayAlg 
{
	/**
	 * A pair of floating-point numbers
	 */
	public static class Pair
	{
		public Pair(double f, double s)
		{
			first = f; 
			second = s;
		}
		
		public double getFirst()
		{
			return first;
		}
		
		public double getSecond()
		{
			return second;
		}
		
		private double first;
		private double second;
	}
	
	public static Pair minmax(double[] values)
	{
		double min = Double.MAX_VALUE;
		double max = Double.MIN_VALUE;
		for (double v : values)
		{
			if (min > v) min = v;
			if (max < v) max = v;
		}
		return new Pair(min, max);
	}
}
