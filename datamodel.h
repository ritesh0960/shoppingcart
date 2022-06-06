#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class product
{
    int id;
    string name;
    int price;

public:
    product(){};
    product(int u_id, string name, int price)
    {
        id = u_id;
        this->name = name;
        this->price = price;
    }
    string getdisplayname()
    {
        return name + " RS " + to_string(price) + "\n";
    }
    string getshortname()
    {
        return name.substr(0, 1);
    }
    friend class item;
    friend class cart;
};
class item
{
    product Product;
    int quantity;

public:
    item(){};
    item(product p, int q) : Product(p), quantity(q){};
    int getitemprice()
    {
        return quantity * Product.price;
    }
    string getiteminfo()
    {
        return to_string(quantity) + " X " + Product.name + " RS " + to_string(quantity * Product.price);
    }
    friend class cart;
};
class cart{
   unordered_map<int,item> items;
   public:
   void addproduct(product Product)
   {
       if(items.count(Product.id)==0)
       {
           item newitem(Product,1);
           items[Product.id]=newitem;

       }
       else
       {
           items[Product.id].quantity+=1;

       }
   }
   int gettotal()
   {
       int total=0;
       for(auto itempair:items)
       {
           auto item_price=itempair.second;
           total+=item_price.getitemprice();

       }
       return total;
   }
   string viewcart()
   {
       if(items.empty())
       {
           return "cart is empty \n";
       }
       string itemized_list;
       int cart_total=gettotal();
       for(auto itempair:items)
       {
           auto item_list=itempair.second;
           itemized_list.append(item_list.getiteminfo()+"  \n");
       }
       return itemized_list + "total amount : Rs. "+to_string(cart_total) + '\n';

   }

   bool isempty()
   {
       return items.empty();
   }

};