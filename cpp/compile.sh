export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/meltpoint/.pyenv/versions/3.8.16/lib/
 g++ src/$1 -I/home/meltpoint/.pyenv/versions/3.8.16/include/python3.8/ -I/home/meltpoint/my_ml/cpp/matplotlib-cpp/lib/python3.8/site-packages/numpy/core/include/ -L/home/meltpoint/.pyenv/versions/3.8.16/lib/ -lpython3.8   -o build/dataset
