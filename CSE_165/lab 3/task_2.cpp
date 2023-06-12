#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string> word;
  std::string C = " ";
  std::string repeat = "";

  int N;

  std:: cout << "Please enter a character and a number: " << std::endl;

  while(N != -2)
  {
    std::cin >> C >> N;

    if (N == -1){
      word.push_back("\n");
    }
    else
    {
      for (int i = 0; i < N; i++)
      {
        repeat += C;
      }
      word.push_back(repeat);
      repeat = "";
    }
  }

  for(int i = 0; i < word.size(); i++)
  {
    if(word[i] == "\n")
    {
      std::cout << "\n";
    }
    std::cout << word[i];
  }
  std::cout << std::endl;
}
