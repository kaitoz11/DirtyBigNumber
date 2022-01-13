/*
	Cau hoi bonus 6
	
Noi dung: "Cong tru nhan chia 2 so nguyen cuc lon,
	lon hon ca kha nang chua cua kieu [long long]"

*/
#include <bits/stdc++.h>
//prototypes
void cleanArr(int *arr, int n);
int len(char *arr, int n);
void str_to_numArr(int *int_arr, char *char_arr, int n);
void output_arr(int *arr, int n);
void sumLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres);
void subtractLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres, int NegSign);
void productLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres);

int main(){
	int isNegative;
	// Gioi han cua gia tri nhap la 300 ky tu
	const int MAX=300;
	char str_num1[MAX], str_num2[MAX];
	
	// Nhap 2 so nguyen
	printf("Nhap so nguyen 1: \n");
	scanf("%s", &str_num1);
	printf("Nhap so nguyen 2: \n");
	scanf("%s", &str_num2);
	
	// chuyen mang char thanh mang int
	int int_num1[MAX], int_num2[MAX],result[MAX*2],temp,len1,len2;
	cleanArr(int_num1,MAX);
	cleanArr(int_num2,MAX);
	cleanArr(result,MAX*2);
	len1=len(str_num1,MAX);
	len2=len(str_num2,MAX);
	str_to_numArr(int_num1, str_num1,len1);
	str_to_numArr(int_num2, str_num2,len2);

	// Menu
	int choice;
	do{
		printf("\n\t---MENU---\n0. Exit\n1. Tong\n2. Hieu\n3. Tich\n4. Thuong\n5. Nhap lieu\n\t----------\nChon phep tinh 0 -> 5:");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				// thoat khoi chuong trinh
				printf("\nClosing the program");
				break;
			case 1:
				// tinh tong 2 so hang
				// temp: so chu so cua tong 2 so hang lon
				if(len1==len2){
					temp=len1+1;
				}else{
					temp=len1>len2?len1:len2;
				}
				printf("\n[so nguyen 1] + [so nguyen 2] = ");
				sumLarge(int_num1, len1, int_num2, len2, result, temp); 
				// In ra ket qua
				output_arr(result,temp);
				// Lam sach mang ket qua
				cleanArr(result,MAX*2);
				break;
			case 2:
				// tinh hieu 2 so hang
				// temp: so chu so cua hieu 2 so hang lon
				temp=len1>len2?len1:len2;
				printf("\n[so nguyen 1] - [so nguyen 2] = ");
				isNegative = 0;
				if(len1==len2){
					for(int i=len1-1;i>=0;i--){
						if(int_num1[i]<int_num2[i])isNegative=1;
					}
				}
				if(len1<len2)isNegative=1;
				if(isNegative){
					subtractLarge(int_num2, len2, int_num1, len1, result, temp, isNegative);	
				}else{
					subtractLarge(int_num1, len1, int_num2, len2, result, temp, isNegative);
				}
				// In ra ket qua
				output_arr(result,temp);
				// Lam sach mang ket qua
				cleanArr(result,MAX*2);
				break;
			case 3:
				// tinh tich 2 so hang
				// temp: so chu so cua tich 2 so hang lon
				temp=len1+len2;
				printf("\n[so nguyen 1] x [so nguyen 2] = ");
				productLarge(int_num1, len1, int_num2, len2, result, temp);
				// In ra ket qua
				output_arr(result,temp);
				// Lam sach mang ket qua
				cleanArr(result,MAX*2);
				break;
			case 4:
				// tinh thuong 2 so hang
				
				// In ra ket qua
				output_arr(result,temp);
				// Lam sach mang ket qua
				cleanArr(result,MAX*2);
				break;
			case 5:
				// Nhap lai du lieu	
				printf("Nhap so nguyen 1: \n");
				scanf("%s", &str_num1);
				printf("Nhap so nguyen 2: \n");
				scanf("%s", &str_num2);
				//lam sach du lieu
				cleanArr(int_num1,MAX);
				cleanArr(int_num2,MAX);
				cleanArr(result,MAX*2);
				// to numArr
				len1=len(str_num1,MAX);
				len2=len(str_num2,MAX);
				str_to_numArr(int_num1, str_num1,len1);
				str_to_numArr(int_num2, str_num2,len2);

				break;
			default:
				printf("\nWrong input!");
				break;
		}
	}while(choice!=0);
	
	return 0;
}

void cleanArr(int *arr, int n){
	for(int i=0;i<n;i++)arr[i]=0;
}

int len(char *arr, int n){
	// Ham tra ve so luong ky tu so cua mang
	int length=0;
	for(int i=0;i<n;i++){
		// ko phai ky tu thuoc ASCII tu 0 -> 9
		if(arr[i]<48 || arr[i]>57)return length;
		length++;
	}
	return length;
}

void output_arr(int *arr, int n){
	int switch1=1;
	for(int i=n-1;i>=0;i--){
		if(arr[i]!=0)switch1=0;
		if(switch1==0)printf("%d",arr[i]);
	}
	// Toan bo mang deu = 0 thi xuat "0"
	if(switch1==1)printf("0");
}

void str_to_numArr(int *int_arr, char *char_arr, int n){
	//"123456789" => [9,8,7,6,5,4,3,2,1]
	// '0' = 48 (ASCII) -> '4' - '0' = 52 - 48 = 4
	for(int i=0;i<n;i++)int_arr[i]=char_arr[n-i-1]-'0';
}

void sumLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres){
	// arr1 + arr2
	int du=0;
	for(int i=0;i<lenres;i++){
		result[i]=(arr1[i] + arr2[i] + du)%10;
		du=(arr1[i]+arr2[i]+du)/10;
	}
}

void subtractLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres, int NegSign){
	// arr1 - arr2 (DK: arr1 >= arr2)
	// result = "-1234" -> [4,3,2,-1]
	int du=0,temp=0;
	for(int i=0;i<lenres;i++){
		if(arr1[i]-du<arr2[i]&&i<=len1){
			temp=10;
		}else{
			temp=0;
		}
		if(len1<len2&&i>len1){
			result[i]=arr2[i]+arr1[i]-du;
		}else{
			result[i]=temp+arr1[i]-arr2[i]-du;
		}
		du=temp==10?1:0;
	}
	// Them dau am
	if(NegSign){
		int j=lenres-1;
		while(result[j]==0){
			j--;
		}
		result[j]=result[j]*(-1);
	}
}

void productLarge(int *arr1, int len1, int *arr2, int len2, int *result, int lenres){
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			result[i+j]+=arr1[i]*arr2[j];
			result[i+j+1]+=result[i+j]/10;
			result[i+j]%=10;
		}
	}
}
