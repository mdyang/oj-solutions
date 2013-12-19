using System;
using System.Collections.Generic;
public class main{
	public static void Main(string[] args){
		int n = int.Parse(Console.ReadLine());
		while((n--)>0){
			int m = int.Parse(Console.ReadLine());
			List<string> l = new List<string>();
			while((m--)>0){
				string t = Console.ReadLine();
				l.Add(t);
			}
			l.Sort((s1,s2)=>compare(s1,s2));
			foreach(string s in l) Console.WriteLine(s);
		}
	}
	private static int compare(string s1,string s2){
		if(s1==null||s2==null)return 0;
		int sizediff=s1.Length-s2.Length;
		int length = s1.Length < s1.Length ? s1.Length:s2.Length;
		for(int i=0;i<length;i++){
			if(s1[i]!=s2[i])return s1[i]-s2[i];
		}
		return sizediff;
	}
}