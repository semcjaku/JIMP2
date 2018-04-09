//
// Created by Kuba on 08-04-18.
//

#include "Matrix.h"
 namespace algebra
 {
     std::string toString(const double value)
     {
         std::ostringstream stream;
         stream << value;
         std::string out = stream.str();
         return out;
     }

     Matrix::Matrix()
     {
         mat_.clear();
         dim_.emplace_back(0);
         dim_.emplace_back(0);
     }

     Matrix::Matrix(const std::initializer_list<unsigned int> &dims) : dim_{dims}
     {
         mat_.clear();
         if(dim_[0]==0 || dim_[1]==0)
             return;
         for(int i=0;i<dim_[0];i++)
         {
             std::vector<std::complex<double>> tmp;
             for(int j=0;j<dim_[1];j++)
                 tmp.emplace_back(0);
             mat_.emplace_back(tmp);
         }
     }

     Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> elem)
     {
        dim_.push_back((unsigned int)elem.size());
        dim_.push_back((unsigned int)(*elem.begin()).size());
        mat_.clear();
        if(dim_[0]==0 || dim_[1]==0)
        {
            dim_[0]=0;
            dim_[1]=0;
            return;
        }
        for (int i = 0; i < dim_[0]; i++)
        {
            mat_.emplace_back(std::vector<std::complex<double>>());
            for (int j = 0; j < dim_[1]; j++)
            {
                mat_[i].push_back(std::complex<double>());
            }
        }
        std::initializer_list<std::vector<std::complex<double>>>::iterator it;
        int i = 0;
        for (it = elem.begin(); it != elem.end(); it++)
        {
            for (int j = 0; j < dim_[1]; j++)
            {
                mat_[i][j] = (*it)[j];
            }
            i++;
        }
     }

     Matrix::Matrix(std::string m)
     {
         mat_.clear();
         std::vector<std::complex<double>> tmp;
         std::complex<double> com_tmp=0.;
         size_t rowend=0, im=m.find('i',0), re=1;
         while(rowend!=std::string::npos)
         {
             rowend=m.find(';',rowend);
             while(im<rowend)
             {
                 com_tmp.real(std::stod(m));
                 com_tmp.imag(std::stod(m.substr(im)));
                 tmp.emplace_back(com_tmp);
                 re=m.find(' ',im);
                 im=m.find('i',re);
             }
             mat_.emplace_back(tmp);
         }
         dim_.push_back((unsigned int)mat_.size());
         dim_.push_back((unsigned int)mat_[0].size());
     }

     Matrix::Matrix(const Matrix& m) {
         mat_.clear();
         dim_=m.dim_;
         mat_=m.mat_;
     }

     Matrix & Matrix::operator=(const Matrix& m) {

         if (this == &m) {
             return *this;
         }

         mat_.clear();
         dim_=m.dim_;
         mat_=m.mat_;
     }

     std::pair<size_t,size_t> Matrix::Size()
     {
         std::pair<size_t,size_t> size;
         size.first=(size_t)dim_[0];
         size.second=(size_t)dim_[1];
         return size;
     }

     std::string Matrix::Print() const
     {
         if(dim_[0]==0 || dim_[1]==0)
             return "[]";
         std::string str="[";
         for(int i=0;i<dim_[0];i++)
         {
             for(int j=0;j<dim_[1];j++)
             {
                 str+=toString(mat_[i][j].real())+"i"+toString(mat_[i][j].imag());
                 if(j<dim_[1]-1)
                     str+=", ";
                 else
                     str+="; ";
             }
         }
         if(str.length()>=2)
            str.erase(str.length()-2,2);
         str+="]";
         return str;
     }

     Matrix Matrix::Add(const Matrix &another) const
     {
         Matrix result;
         if(dim_==another.dim_)
         {
             result.dim_=dim_;
             for(int i=0;i<dim_[0];i++)
             {
                 std::vector<std::complex<double>> tmp;
                 for(int j=0;j<dim_[1];j++)
                     tmp.emplace_back(mat_[i][j]+another.mat_[i][j]);
                 result.mat_.emplace_back(tmp);
             }
         }
         return result;
     }

     Matrix Matrix::Sub(const Matrix &another)
     {
         Matrix result;
         if(dim_==another.dim_)
         {
             result.dim_=dim_;
             for(int i=0;i<dim_[0];i++)
             {
                 std::vector<std::complex<double>> tmp;
                 for(int j=0;j<dim_[1];j++)
                     tmp.emplace_back(mat_[i][j]-another.mat_[i][j]);
                 result.mat_.emplace_back(tmp);
             }
         }
         return result;
     }

     Matrix Matrix::Mul(const Matrix &another)
     {
         Matrix result;
         if(dim_[1]==another.dim_[0])
         {
             result.dim_[0]=dim_[0];
             result.dim_[1]=another.dim_[1];
             for(int i=0;i<dim_[0];i++)
             {
                 std::vector<std::complex<double>> tmp;
                 for(int j=0;j<another.dim_[1];j++)
                 {
                     std::complex<double> sum=0.;
                     for(int k=0;k<dim_[1];k++)
                         sum+=mat_[i][k]*another.mat_[k][j];
                     tmp.emplace_back(sum);
                 }
                 result.mat_.emplace_back(tmp);
             }
         }
         return result;
     }

     Matrix Matrix::Pow(int n)
     {
         Matrix result;
         result=*this;
         if(n==0)
         {
             for(int i=0;i<result.dim_[0];i++)
             {
                 for(int j=0;j<result.dim_[1];j++)
                 {
                     if(i==j)
                         result.mat_[i][j]=1;
                     else
                         result.mat_[i][j]=0;
                 }
             }
             return result;
         }
         for(int i=0;i<n-1;i++)
             result=result.Mul(*this);
         return result;
     }
 }