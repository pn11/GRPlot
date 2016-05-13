# GRPlot

とりあえずGitHubに投稿してみたかっただけ。  
ROOT based Gnuplot clone になるはずだった。  
ROOTでGnuplotみたく簡単にグラフつくりたいと思って作り始めたけどめんどくさくなった。TApplicationとか使ったことないし。最初ROOTPLOTっていう名前にしてたけどもうあるようだし、RooPlotもあるし、RplotもRtPlotあるし、この名前に。  

## できること

```
plot sin(x)
```

とか

```
plot exp(2*x)
```

とかするとその関数が描ける。今のところ1回しか描けず、2回目はエラーになる。

```
demo
```

と入力すると二次元のあらかじめ用意してある `test.dat` からグラフを描く。

```
q
```  

```
.q
```  

```
exit
```  

で終了できる。

```
ls
```

でカレントディレクトリのファイルを表示する。

## 問題

- ~~TApplication と readline の共存がよくわからない。TRintを使うべきなのか。~~ TRint を使うようにした。 <http://be.nucl.ap.titech.ac.jp/~kondo/moin/moin.cgi/APROOT> を参考にした。これで機能を追加していけばできそう。
- スペースだけでエンターを押すと segmentation violation になる。




