package com.example.learnjni;

import java.util.Date;
import java.util.Random;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	private Random mRandom;
	public static final int LENGTH = 10;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
       mRandom = new Random(new Date().getTime());
    }	
    
	
	public void onBtnClick(View v) {
		int id = v.getId();
		if(id == R.id.btn_get_string_from_jni){
			makeToast(NdkUtils.getStringFromJni());
		}
		else if(id == R.id.btn_convert_string_from_jni){
			makeToast(NdkUtils.convertToUpper("Hello World from java"));
		}
		else if(id == R.id.btn_intarray){
			makeToast("total:" + NdkUtils.totalIntArray(generateInts()));
		}
		else if(id == R.id.btn_intarray_add10){
			int[] add10 = NdkUtils.IntArrayAdd10(generateInts());
			makeToast(intsToString(add10));
		}
		
	}
	
	public void makeToast(String msg){
		Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();
	}
	
	public int[] generateInts(){
		int[] numbers = new int[LENGTH];
		for(int i = 0; i < numbers.length; i++){
			numbers[i] = mRandom.nextInt(100);
			System.out.print(numbers[i] + " ");
		}
		System.out.println();
		return numbers;
	}
	
	public String intsToString(int[] ints){
		StringBuilder sb = new StringBuilder();
		for (int i : ints) {
			sb.append(i + ", ");
		}
		return sb.toString();
	}
}
