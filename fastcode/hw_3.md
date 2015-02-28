# Homework 3

Task 0: 用完记得关掉

Task 1:

+ export PATH=$PATH:$HOME/hadoop-2.4.0/bin
+ export JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64
+ wget https://cmu.box.com/shared/static/2fwqjutnf8u299sbotkgqamoc7iweawx.gz -O Proj3.tar.gz
+ tar –zxvf Proj3.tar.gz
+ cd Proj3
+ mkdir –p data/tweets10m
+ cd data/tweets10m
+ wget https://cmu.box.com/shared/static/701hqlebgkpek9n9qtcd2vqzt6k98x84.bz2 -O tweets10m.txt.bz2
+ bunzip2 tweets10m.txt.bz2
+ # Split out a small trunk of data
+ mkdir ../tweets1m
+ head -1000000 tweets10m.txt > ../tweets1m/tweets1m.txt
+ ls –l lib/ 
+ ant
+ hadoop jar 18645-proj3-0.1-latest.jar -program ngramcount -n 1 -input data/tweets10m/tweets10m.txt -output data/ngram10m 
+ hadoop jar 18645-proj3-0.1-latest.jar -program hashtagsim -input data/tweets1m/tweets1m.txt -output data/hashtag1m -tmpdir tmp

Task 3:

dawang
Access Key ID: AKIAJYPQBVXAXLYJDXBQ
Secret Access Key: 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

To Step 2 
