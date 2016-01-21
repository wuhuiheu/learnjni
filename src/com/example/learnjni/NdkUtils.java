package com.example.learnjni;

public final class NdkUtils {
	static{
		System.loadLibrary("learnjni");
	}
	public native static void setNumber(int number);
	public native static int getNumber();
	public native static String getStringFromJni();
	public native static String convertToUpper(String string);
	public native static int totalIntArray(int[] numbers);
	public native static int[] IntArrayAdd10(int[] numbers);
	public native static String[] returnStringArray();
	public native static String getUserName(User users);
	
}
