= GitHub Actionsを利用する

== ワークフローファイルを定義する

2章で作成したディレクトリを、GitHub Actionsでビルドするように設定しましょう。といっても、書いてあることはわかりやすいです。

//listnum[mainyml][.github/workflows/main.yml][yaml]{
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

ここまですべて準備できたら、この書籍のディレクトリをコミットし、GitHubにpushすることで、ビルドが実行されます。概ねビルドは1回10分程度かかりますので、しばらくお待ちください。その後、レポジトリのページへ行くと、Latest commitの隣に緑のチェックマークがあるはずです。それが黄色い丸の場合は、まだ実行中です。しばらくしたらページをリロードして確認してください。もし赤いバツ印だった場合、ビルドに失敗しています。Action側の間違いか、本側の間違いか、ログを読んで確認してください。

緑のチェックマークを押すと、All checks have passedというメッセージとともに、定義したワークフローを開くことができます。Detailsを押してください。

その後、Artifactsというところを押すと、成果物をダウンロードできるようになっているので、各成果物をダウンロードしてください。なお、各成果物はzipファイルに入っていますので、解凍することをお忘れなく。

PDFファイルはそのまま入稿可能な形になっていますので、各印刷所へ入稿してください。ePubファイルはePubリーダーで読める形になっていますから、ePub形式で頒布する場合はそれを使ってください。