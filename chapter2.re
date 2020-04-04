= Re:VIEWで本を作る

== Re:VIEWとは

Re:VIEWとは、電子書籍と紙書籍のための、簡単に記述ができるデジタル出版ツールです。このツールのページは@<href>{https://reviewml.org/ja/}です。

== Re:VIEWに必要なもの

Re:VIEWをインストールするにはRubyとRubyGemsが必要です。また、PDFを作成する場合、TeX Liveを使ってLaTeXのインストールも合わせて必要となります。

== インストールする

必要なツールのインストールが終わったら、gem install reviewのコマンドでRe:VIEWをインストールします。それだけです。

== プロジェクトを作成する

プロジェクトを作成するには、review-initコマンドを使用します。最低限review-init [ディレクトリ名]だけで作成できますが、ウィザード形式で文字数なども指定したい場合はreview-init -w [ディレクトリ名]を指定したあと、@<href>{http://localhost:18000/}へアクセスして、ウィザードで指定してください。

ここまで終わったら、実際に原稿を書いていきます。最低限触らないといけないのは、reファイルとcatalog.yml、それとconfig.ymlの3つです。その3つさえ触ればだいたいどうにかなります。

実際にこの本はRe:VIEWを用いて書いてます。@<href>{https://github.com/mh35/github_actions_review}を参照してください。