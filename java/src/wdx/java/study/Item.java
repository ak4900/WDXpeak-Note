package wdx.java.study;

/**
 * An item with a description and a part number
 * @author wangda
 * @version v1.0 2013-10-29
 */
public class Item implements Comparable<Item>
{
	public Item(String aDescription, int aPartNumber)
	{
		description = aDescription;
		partNumber = aPartNumber;
	}
	
	public String getDescription()
	{
		return description;
	}
	
	public String toString()
	{
		return "[description=" + description + ", partNumber=" + partNumber + "]";
	}
	
	public boolean equals(Object otherObject)
	{
		if (this == otherObject) return true;
		if (otherObject == null) return false;
		if (getClass() != otherObject.getClass()) return false;
		Item other = (Item) otherObject;
		return description.equals(other.description) && partNumber == other.partNumber;
	}
	
	public int hashCode()
	{
		return 13 * description.hashCode() + 17 * partNumber;
	}
	
	@Override
	public int compareTo(Item o) 
	{
		return partNumber - o.partNumber;
	}
	
	private String description;
	private int partNumber;
}
