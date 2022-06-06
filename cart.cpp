#include <bits/stdc++.h>
#include "datamodel.h"
using namespace std;
vector<product> allproduct = {
    product(1, "apple", 26),
    product(3, "mango", 16),
    product(2, "guavava", 36),
    product(5, "banana", 56),
    product(4, "strawberry", 29),
    product(6, "pine_apple", 20)

};
product * chooseproduct()
{
    string productlist;
    cout<<"Available Products:-"<<endl;
    for(auto product:allproduct)
    {
        productlist.append(product.getdisplayname());
    }
    cout<<productlist<<endl;
    cout<<"_________________________________________________"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allproduct.size();i++)
    {
        if(allproduct[i].getshortname()==choice)
        {
            return &allproduct[i];
        }
    }
    cout<<"product not found"<<endl;
    return NULL; 
}
bool checkout(cart &Cart)
{
    if(Cart.isempty())
    {
        return false;
    }
    int total=Cart.gettotal();
    cout<<"pay in cash"<<endl;
    int paid;
    cin>>paid;
    if(paid>=total)
    {
        cout<<"change  "<<paid-total<<endl;
        cout<<"thank you for shopping"<<endl;
        return true;
    }
    else
    {
        cout<<"not enough cash!"<<endl;
    }
}


int main()
{
    char action;
    cart Cart;
    while (true)
    {
        cout << "select an action__(a)dd items,(v)iew cart,(C)heckout" << endl;
    
    cin>>action;
    if(action=='a')
    {
        product * Product=chooseproduct();
        if(Product!=NULL)
        {
            cout<<"Added to the cart :-"<<Product->getdisplayname()<<endl;
           // cart.addproduct
           Cart.addproduct(*Product);
        }
    }
        else if(action=='v')
        {
            cout<<"______________________________________________________________"<<endl;
            cout<<Cart.viewcart()<<endl;
            cout<<"_______________________________________________________________"<<endl;

        }
        else{
            Cart.viewcart();
            if(checkout(Cart))
            {
                break;
            }
            return 0;
        }
        
    }
    
}