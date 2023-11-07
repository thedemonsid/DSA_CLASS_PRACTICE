 #include<bits/stdc++.h>
using namespace std;
//function to create sparse matrix
/* his code creates a new representation of the input matrix, where it stores the
 dimensions of the original matrix and a list of non-zero elements with their row and column 
 indices. The code counts how many non-zero elements there are in the original matrix and stores
  this count in the metadata. This can be useful for saving memory when the majority of elements
   in the matrix are zero.

*/
vector<vector<int>>create(vector<vector<int>>matrix){
    vector<vector<int>>sparse_matrix;
    vector<int>temp1;
    temp1.push_back(matrix.size());
    temp1.push_back(matrix[0].size());
    temp1.push_back(0);
    sparse_matrix.push_back(temp1);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
             if(matrix[i][j]!=0){
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(matrix[i][j]);
                sparse_matrix.push_back(temp);
                sparse_matrix[0][2]++;
             }
        }
    }
    return sparse_matrix;
}
//function to add two sparse matrix
vector <vector<int>> add(vector<vector<int>>a,vector<vector<int>>b){
    //first element of sparse matrix is number of rows,columns and non zero elements
    /*
    this function combines two matrices into a new one while ensuring they have compatible dimensions.
     It also keeps track of non-zero elements in the resulting matrix and sorts them by their 
     row and column indices.
    */
      if(a[0][0]!=b[0][0]||a[0][1]!=b[0][1]){
          cout<<"Invalid matrix";
          return {};
      };
        vector<vector<int>>c;
        vector<int>temp1;
        temp1.push_back(a[0][0]);
        temp1.push_back(a[0][1]);
        temp1.push_back(0);
        c.push_back(temp1);
        int i=1,j=1;
        while(i<a.size()&&j<b.size()){
            if(a[i][0]<b[j][0]){
                c.push_back(a[i]);
                i++;
            }
            else if(a[i][0]>b[j][0]){
                c.push_back(b[j]);
                j++;
            }
            else{
                if(a[i][1]<b[j][1]){
                    c.push_back(a[i]);
                    c[0][2]++;
                    i++;
                }
                else if(a[i][1]>b[j][1]){
                    c.push_back(b[j]);
                    c[0][2]++;
                    j++;
                }
                else{
                    vector<int>temp;
                    temp.push_back(a[i][0]);
                    temp.push_back(a[i][1]);
                    temp.push_back(a[i][2]+b[j][2]);
                    c.push_back(temp);
                    c[0][2]++;
                    i++;
                    j++;
                }
            }
        }
        sort(c.begin()+1,c.end());
        return c;
}
//function to multiply two sparse matrix
/*
 this function performs matrix multiplication, ensuring the matrices have 
 compatible dimensions. It keeps track of non-zero elements in the resulting
  matrix and sorts them by their row and column indices.
*/
vector<vector<int>>multiply(vector<vector<int>>a,vector<vector<int>>b){
    if(a[0][1]!=b[0][0]){
        cout<<"Invalid matrix";
        return {};
    }
    vector<vector<int>>c;
    vector<int>temp1;
    temp1.push_back(a[0][0]);
    temp1.push_back(b[0][1]);
    temp1.push_back(0);
    c.push_back(temp1);
    int i=1,j=1;
    while(i<a.size()&&j<b.size()){
        if(a[i][0]<b[j][0]){
            i++;
        }
        else if(a[i][0]>b[j][0]){
            j++;
        }
        else{
            if(a[i][1]<b[j][1]){
                i++;
            }
            else if(a[i][1]>b[j][1]){
                j++;
            }
            else{
                vector<int>temp;
                temp.push_back(a[i][0]);
                temp.push_back(b[j][1]);
                temp.push_back(a[i][2]*b[j][2]);
                c.push_back(temp);
                c[0][2]++;
                i++;
                j++;
            }
        }
    }
    sort(c.begin()+1,c.end());
    return c;
}
// Function to display the sparse matrix
/*
 this code demonstrates the creation and manipulation of sparse matrices,
  showcasing addition and multiplication operations on them, and provides a way to display the results.
*/
void display(vector<vector<int>>sparse_matrix){
    for(int i=0;i<sparse_matrix.size();i++){
         for(int j=0;j<sparse_matrix[i].size();j++){
              cout<<sparse_matrix[i][j]<<" ";
         }
         cout<<endl;
    }
}
int main(){
    vector<vector<int>>matrix1={{1,0,0,0,0},{0,2,9,0,0},{0,0,3,0,0},{0,0,0,4,0},{0,0,0,0,5}};
    vector<vector<int>>matrix2={{1,0,0,3,0},{0,2,9,0,0},{0,0,3,0,100},{0,3,0,4,0},{24,0,0,0,5}};
    vector<vector<int>>sparse_matrix1=create(matrix1);
    vector<vector<int>>sparse_matrix2=create(matrix2);

vector<vector<int>>sparse_matrix3=add(sparse_matrix1,sparse_matrix2);
display(sparse_matrix3);
cout<<endl;
sparse_matrix3=multiply(sparse_matrix1,sparse_matrix2);
display(sparse_matrix3);
     return 0;
}