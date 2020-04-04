= GitHub Actionsを利用する

== ワークフローファイルを定義する

2章で作成したディレクトリを、GitHub Actionsでビルドするように設定しましょう。といっても、書いてあることはわかりやすいです。

//listnum[mainyml][main.yml][yaml]{
on: [push]
jobs:
  build_job:
    runs-on: ubuntu-latest
    name: Build book
    steps:
      -
        name: Checkout
        uses: actions/checkout@v2
      -
        name: Build
        uses: mh35/review_action@v1
      -
        name: Upload PDF artifact
        uses: actions/upload-artifact@v1
        with:
          name: book.pdf
          path: book.pdf
      -
        name: Upload ePub artifact
        uses: actions/upload-artifact@v1
        with:
          name: book.epub
          path: book.epub
//}

まず、pushのたびに実行すると指定します。ubuntu-latestで動作すると指定していますが、これは技術書典8時点ではUbuntu 18.04上で動作することを意味します。アクションは4つを順次実行します。最初のは、レポジトリをチェックアウトするという意味です。その次は、mh35/review_actionレポジトリで定義されたアクションを実行するという意味です。そのレポジトリのどのバージョンを用いるかというと、v1タグのバージョンを用います。レポジトリ名とバージョンは適宜差し替えてください。最後に、book.pdfとbook.epubを成果物として保存するという意味のアクション2つを行います。

== GitHubにpushする

ここまですべて準備できたら、この書籍のディレクトリをコミットし、GitHubにpushすることで、ビルドが実行されます。概ねビルドは1回10分程度かかりますので、気長にお待ちください。そうして出来上がったのがこの本です。