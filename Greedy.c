#include <stdio.h>
int main()
{
  float weight[50],profit[50],ratio[50],TotalProfit,capacity,amount;
  int n,i,j;
  printf("Enter the number of items : ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("Enter weight and profit for the item [%d]:\n",i);
    scanf("%f%f",&weight[i],&profit[i]);
  }
  
  printf("Enter the capacity of knapsack :\n");
  scanf("%f",&capacity);
  
  for(i=0;i<n;i++)
  {
     ratio[i] = profit[i]/weight[i];
  }
  
  int temp;
  
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(ratio[i]<ratio[j])
      {
    
       temp = ratio[i];
       ratio[i] = ratio[j];
       ratio[j] = temp;
       
       temp = profit[i];
       profit[j] = profit[i];
       profit[j] = temp;
       
       temp = weight[i];
       weight[j] = weight[i];
       weight[i] = temp;
      }
    }
  }    
  
  printf("knapsack problems using greedy algorithm:\n");
  for(i=0;i<n;i++)
  {
    if(weight[i]>capacity)
      break;   
    else
    {
      TotalProfit = TotalProfit +profit[i];
      capacity = capacity - weight[i];
    }
  }
  
  if(i<n)
  {
    TotalProfit = TotalProfit + (ratio[i] * capacity);
    printf("\nThe maximum profit is : %f\n",TotalProfit);
    return 0;
  }
}
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
       
      
