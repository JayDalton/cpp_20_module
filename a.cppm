export module b;
import <cstdio>;

export namespace data
{
   int get()
   {
      return 123;
   }
}

template<typename T>
concept floatlike = requires (T t) { static_cast<float>(t); };

export namespace io
{
   void print(floatlike auto x)
   {
      printf("%f\n", static_cast<float>(x));
   }
}

