
C++ Callback Solution

 www.partow.net	 .: Home :.   .: Links :.   .: Search :.   .: Contact :. 

Main Menu
About
Programming
Projects
Miscellaneous

Topics
String Toolkit Library
C++ Mathematical Expression Library
Callbacks In C++
General Purpose Hash Function Algorithms
C++ Bitmap Library
C++ TCP Proxy Server
C++ Bloom Filter Library
C++ DSV Filter Library
C++ Vector Expression Template Library
C++ Lexer Library
C++ Date And Time Parsing Utilities
C++ Logging Toolkit
C++ Summation Toolkit
Wykobi Computational Geometry Library
Schifra Reed Solomon Error Correcting Code Library
C++ Makefile Template
Win32 Registry Activity Monitor
String Tokenizer
Primitive Polynomials

www.partow.net Menu Logo - Copyright Arash Partow

Valid XHTML 1.0!


The Problem
The Solution
Usage Of The Template
Variable Argument CallBack Template
Future Directions
A Quick Note
A Final Thought
An Update
Compatibility
C++ Templated Callback Solution License
Download

The Problem

Unlike other languages such as Object Pascal, Ada, Java and C#, C++ does not offer a native solution to the issue of passing a class's method as a callback function. In the C language these are known as functors and exist very commonly in many event driven applications. The main problem centers around the fact that multiple instances of a particular class will result in different memory locations for each instantiation. This leads to the need of having not only the method pointer but also a pointer to the instance itself. The problem's definition brings about an intuitive solution which falls within the realms of templates and compile time instantiation and specialization.

Note 1: As of 2008 there are currently two proposed standard additions that should rectify this issue and allow for C++ to natively accommodate anonymous functions. These additions are lambdas and std::function/std::bind.

The Solution

The solution presented here is designed to take only one parameter. However as more more compilers begin to correctly implement the future C++ standard then variadic template arguments such as template lists "..." (C++ Templates, The Complete Guide) will become a reality allowing for frameworks that can easily cater to arbitrary parameter sets. That said, once the single parameter solution has been presented a crude workaround for multiple parameters will also be discussed.


template <class Class, typename ReturnType, typename Parameter>
class SingularCallBack
{
public:

   typedef ReturnType (Class::*Method)(Parameter);

   SingularCallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter parameter)
   {
      return (class_instance_->*method_)(parameter);
   }

   ReturnType execute(Parameter parameter)
   {
      return operator()(parameter);
   }

private:

   Class* class_instance_;
   Method method_;
};

Usage Of The Template

Usage of the template is very simple. The template itself can be instantiated as an object pointer or just as a simple class. When being used as an object pointer, C++ has another painful limitation and that is that the operator() can not be invoked without dereferencing the object pointer, a quick and dirty solution was to place an execute() method within the template, which calls the operator() from within the template itself. Other than that little problem, instantiating the SingularCallBack as an object pointer will allow you to have a vector of callbacks, or any other kind of grouping which is highly desirable in event driven programming.

Lets assume the following 2 classes exist, and that we want to have methodB() as our callback method. From the code we can see that when methodB() is invoked with the paramter of class A, methodB() will then invoke the method output() in class A. The proof that the callback really worked is if we see the line "I am class A :D" in the stdout.


class A
{
public:

   void output()
   {
      std::cout << "I am class A :D" << std::endl;
   }
};

class B
{
public:

   bool methodB(A a)
   {
      a.output();
      return true;
   }
};

There are two ways one can invoke the callback from an object pointer, the initial method is to derefrence the object pointer and run the callback method (ie: () operator) the second option is to run the execute() method.


A a;
B b;

SingularCallBack<B,bool,A>* cb;
cb = new SingularCallBack<B,bool,A>(&b,&B::methodB);

if((*cb)(a))
{
   std::cout << "CallBack Fired Successfully!" << std::endl;
}
else
{
   std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
}


A a;
B b;

SingularCallBack<B,bool,A>* cb;
cb = new SingularCallBack<B,bool,A>(&b,&B::methodB);

if(cb->execute(a))
{
   std::cout << "CallBack Fired Successfully!" << std::endl;
}
else
{
   std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
}

This is how you would instansiate and use the callback template as a normal object:


A a;
B b;
SingularCallBack<B,bool,A>cb(&b,&B::methodB);

if(cb(a))
{
   std::cout << "CallBack Fired Successfully!" << std::endl;
}
else
{
   std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
}

A more complicated example of how the callback template can be used is as follows:


class AClass
{
public:

   AClass(unsigned int id)
   : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};


typedef SingularCallBack <AClass, bool, const std::string&> ACallBack;


int main()
{
   std::vector<ACallBack> callback_list;

   AClass a1(1);
   AClass a2(2);
   AClass a3(3);

   callback_list.push_back(ACallBack(&a1, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a2, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a3, &AClass::AMethod));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i]("abc");
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i].execute("abc");
   }

   return 0;
}


A slightly more complicated example than the previous one shows how you can mix classes derived from a common base class into a container and hence have the most derived method (originating from the base class) invoked.


class BaseClass
{
public:

   virtual ~BaseClass(){}

   virtual bool DerivedMethod(const std::string& str){ return true; }

};

class AClass : public BaseClass
{
public:

   AClass(unsigned int id)
   : id_(id)
   {}

   bool AMethod(const std::string& str)
   {
      std::cout << "AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method AClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

   unsigned int id_;
};

class BClass : public BaseClass
{
public:

   BClass(unsigned int id)
   : id_(id)
   {}

   bool BMethod(const std::string& str)
   {
      std::cout << "BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

   bool DerivedMethod(const std::string& str)
   {
      std::cout << "Derived Method BClass[" << id_ << "]: " << str << std::endl;
      return true;
   }

private:

 unsigned int id_;
};


typedef SingularCallBack <BaseClass, bool, const std::string&> BaseCallBack;


int main()
{
   std::vector<BaseCallBack> callback_list;

   AClass a(1);
   BClass b(2);

   callback_list.push_back(BaseCallBack(&a, &BaseClass::DerivedMethod));
   callback_list.push_back(BaseCallBack(&b, &BaseClass::DerivedMethod));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i]("abc");
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      callback_list[i].execute("abc");
   }

   return 0;
}


For the sake of simplicity and clarity, necessary code relating to instance validation has not been included, in real-world implementations instances of classes should be passed around such frame-works using smart pointer encapsulation classes. The STL provides two excellent choices the auto_ptr and its successor the shared_ptr. Also in the book "Modern C++ Design" by Andrei Alexandrescu, a policy design oriented smart-pointer class is made available. In all three cases each solution has its own advantages and disadvantages so it is left up to the end user to decide which solution best meets their needs.


Variable Argument CallBack Template

Below is a demonstration of a simple template pattern for overloading a typical CallBack class in order to present multiple interfaces for callback methods of varying argument counts. For simplicity in the example below the CallBack class can support methods with varying argument counts from 0 to 4, in theory more can be added.


template <class Class, typename ReturnType, typename Parameter1 = void,
                                            typename Parameter2 = void,
                                            typename Parameter3 = void,
                                            typename Parameter4 = void>
class CallBack
{
public:

   typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3, Parameter4);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
   {
      return (class_instance_->*method_)(p1, p2, p3, p4);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3, Parameter4 p4)
   {
      return operator()(p1, p2, p3, p4);
   }

private:

   Class* class_instance_;
   Method method_;
};


template <class Class, typename ReturnType, typename Parameter1,
                                            typename Parameter2,
                                            typename Parameter3>
class CallBack <Class, ReturnType, Parameter1, Parameter2, Parameter3>
{
public:

   typedef ReturnType (Class::*Method)(Parameter1, Parameter2, Parameter3);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter1 p1, Parameter2 p2, Parameter3 p3)
   {
      return (class_instance_->*method_)(p1, p2, p3);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2, Parameter3 p3)
   {
      return operator()(p1, p2, p3);
   }

private:

   Class* class_instance_;
   Method method_;
};


template <class Class, typename ReturnType, typename Parameter1, typename Parameter2>
class CallBack <Class, ReturnType, Parameter1, Parameter2>
{
public:

   typedef ReturnType (Class::*Method)(Parameter1,Parameter2);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter1 p1, Parameter2 p2)
   {
      return (class_instance_->*method_)(p1, p2);
   }

   ReturnType execute(Parameter1 p1, Parameter2 p2)
   {
      return operator()(p1, p2);
   }

private:

   Class* class_instance_;
   Method method_;
};


template <class Class, typename ReturnType, typename Parameter>
class CallBack <Class, ReturnType, Parameter>
{
public:

   typedef ReturnType (Class::*Method)(Parameter);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()(Parameter p1)
   {
      return (class_instance_->*method_)(p1);
   }

   ReturnType execute(Parameter p1)
   {
      return operator()(p1);
   }

private:

   Class*  class_instance;
   Method  method;
};


template <class Class, typename ReturnType>
class CallBack <Class, ReturnType>
{
public:

   typedef ReturnType (Class::*Method)(void);

   CallBack(Class* class_instance, Method method)
   : class_instance_(class_instance),
     method_(method)
   {}

   ReturnType operator()()
   {
      return (class_instance_->*method_)();
   }

   ReturnType execute()
   {
      return operator()();
   }

private:

   Class* class_instance_;
   Method method_;
};

The above template patterns can be invoked as follows:


class AClass
{
public:

  AClass(unsigned int id)
  : id_(id)
  {}

  bool AMethod(const std::string& str)
  {
     std::cout << "AClass[" << id_ << "]: " << str << std::endl;
     std::cout.flush();
     return true;
  }

  bool method4(int a, int b, int c, int d)
  {
     std::cout << "Method - 4" << std::endl;
     return true;
  }

  bool method3(int a, int b, int c)
  {
     std::cout << "Method - 3" << std::endl;
     return true;
  }

  bool method2(int a, int b)
  {
     std::cout << "Method - 2" << std::endl;
     return true;
  }

  bool method1(int a)
  {
     std::cout << "Method - 1" << std::endl;
     return true;
  }

  bool method0()
  {
     std::cout << "Method - 0" << std::endl;
     return true;
  }

  void method()
  {
     std::cout << "Method - v" << std::endl;
  }

private:

 unsigned int id_;
};

typedef CallBack<AClass, bool, int, int ,int, int> callback_type4;
typedef CallBack<AClass, bool, int, int ,int>      callback_type3;
typedef CallBack<AClass, bool, int, int>           callback_type2;
typedef CallBack<AClass, bool, int>                callback_type1;
typedef CallBack<AClass, bool>                     callback_type0;
typedef CallBack<AClass, void>                     callback_typev;

int main()
{
   AClass aclass(1);

   callback_type4 cb4(&aclass, &AClass::method4);
   callback_type3 cb3(&aclass, &AClass::method3);
   callback_type2 cb2(&aclass, &AClass::method2);
   callback_type1 cb1(&aclass, &AClass::method1);
   callback_type0 cb0(&aclass, &AClass::method0);
   callback_typev cbv(&aclass, &AClass::methodv);

   std::vector<std::pair<int,void*> > callback_list;

   callback_list.push_back(std::pair<int,void*>( 4, static_cast<void*>(&cb4)));
   callback_list.push_back(std::pair<int,void*>( 3, static_cast<void*>(&cb3)));
   callback_list.push_back(std::pair<int,void*>( 2, static_cast<void*>(&cb2)));
   callback_list.push_back(std::pair<int,void*>( 1, static_cast<void*>(&cb1)));
   callback_list.push_back(std::pair<int,void*>( 0, static_cast<void*>(&cb0)));
   callback_list.push_back(std::pair<int,void*>(-1, static_cast<void*>(&cbv)));

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      switch (callback_list[i].first)
      {
         case  4: (*static_cast<callback_type4*>(callback_list[i].second))(1,2,3,4);
                  break;

         case  3: (*static_cast<callback_type3*>(callback_list[i].second))(1,2,3);
                  break;

         case  2: (*static_cast<callback_type2*>(callback_list[i].second))(1,2);
                  break;

         case  1: (*static_cast<callback_type1*>(callback_list[i].second))(1);
                  break;

         case  0: (*static_cast<callback_type0*>(callback_list[i].second))();
                  break;

         case -1: (*static_cast<callback_typev*>(callback_list[i].second))();
                  break;
      }
   }

   for (unsigned int i = 0; i < callback_list.size(); ++i)
   {
      switch (callback_list[i].first)
      {
         case  4: static_cast<callback_type4*>(callback_list[i].second)->execute(1,2,3,4);
                  break;

         case  3: static_cast<callback_type3*>(callback_list[i].second)->execute(1,2,3);
                  break;

         case  2: static_cast<callback_type2*>(callback_list[i].second)->execute(1,2);
                  break;

         case  1: static_cast<callback_type1*>(callback_list[i].second)->execute(1);
                  break;

         case  0: static_cast<callback_type0*>(callback_list[i].second)->execute();
                  break;

         case -1: static_cast<callback_typev*>(callback_list[i].second)->execute();
                  break;
      }
   }

   return 0;
}

Future Directions

Possible extensions to the SingularCallBack template would be to make the number of parameters for the callback variable. At the moment the standard compilers such as GCC, Intel C++ compiler and Borland C++ Builder and BuilderX don't fully support templates as have been described in the proposed C++0x language standard. Once the "..." syntax has been approved for variable template parameters and implemented in the major compilers I will update this page for variable parameters. Until then the only way I can see variable number of parameters being passed would be to overload template implementations of CallBack with differing parameter counts, which in my opinion is a very inadequate solution.

A Quick Note

If you found it difficult understanding the above mentioned syntax or think you might require a refresher in method pointers and how they are used in the C++ language then the Simple C++ Callback Examples might be just what you need to get started.

A Final Thought

Templates and the whole meta-programming paradigm are truly powerful tools which programmers of the C++ language and to a greater extent any other language which supports the paradigm should and must take advantage of any chance they get. They help solve complexities which would require the development of error prone and not yet fully understood static software patterns. Templates encourage generic programming, they motivate a programmer to think outside of their current view point and see future uses of what they are building hence adding to the resuability of their code. However not all problems are suited for template based solutions, and just like all things in life too much of a good thing can make you sick. Being a good programmer not only means knowing what solution will solve which problem, but also to knowing what solution will cause more problems than the problem they are solving. In my opinion together with portability the next most important factor which would make a programmer's code base immortal would be the genericity of their code.

An Update

2006-07-21 Recently the TR1 proposal has begun to gain momentum, and is very likely to become standardized within the next few years. As part of the TR1 proposal is the Bind mechanism/library found in the BOOST C++ library. This form of Bind will definitely be the future in C++ with regards to callback and delegate mechanisms. For production purposes it is advised that the Bind library be used.

C++ Templated Callback Solution License

Free use of the C++ Templated Callback Solution and the Simple C++ Callback Examples is permitted under the guidelines and in accordance with the most current version of the "Common Public License."


Compatibility

The C++ Templated Callback Solution and the Simple C++ Callback Examples are both known to be compatible with the following C++ compilers:

GNU Compiler Collection (3.3.1-x+)
Clang/LLVM (1.1+)
Intel® C++ Compiler (8.x+)
Microsoft Visual Studio C++ Compiler (7.x+)

Download

C++ Templated Callback Source Code

Simple C++ Callback Examples Source Code




© Arash Partow. All Rights Reserved.
