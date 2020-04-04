= GitHub Actionsの準備

== GitHub Actionsとは

GitHub Actionsとは、GitHubが2019年に開始した、継続的インテグレーションツールです。GitHubレポジトリに変更が加えられたとき、ビルドやテストが自動で実行され、それにより製品の質を保証したり、いちいちビルドスクリプトやデプロイスクリプトを実行したりする手間を省くことができます。

GitHub Actionsは誰でも利用することができますが、利用するためには設定が必要になります。この本では、その設定をメインに書いていきます。

この本の原稿自体はオープンソースで記述されています。@<href>{https://github.com/mh35/github_actions_review}にレポジトリがありますので、ぜひご活用ください。

== Actionを定義する

Actionは、何を実行するのかを定義したものです。このActionを定義するためには、Dockerの知識が必要となります。チュートリアルは、@<href>{https://help.github.com/ja/actions/building-actions/creating-a-docker-container-action}に書いてあるのですが、少し分かりづらいので、まとめると、

 1. ビルド用のスクリプトを作成する
 2. Dockerfileを作成する
 3. 説明用のREADMEを作成する(オプション)

ということです。というわけで、まずはそれぞれ考えていきましょう。

=== ビルド用のスクリプトを作成する

まず、ビルド用のスクリプトがどんな感じになるかを考えます。ビルド用のスクリプトは、ワークスペースのディレクトリへcdした後、必要なビルドを実行する形になるはずですね。ワークスペースのディレクトリはGITHUB_WORKSPACEという環境変数で参照できるので、スクリプトはこのようなものになるはずです。

//listnum[entrypoint][entrypoint.sh][bash]{
#!/bin/bash

set -eu

cd $GITHUB_WORKSPACE
bundle install
bundle exec rake pdf
bundle exec rake epub
//}

もしpdfとepubの2フォーマットのうちどちらかがいらないならば、そこの部分を削除すれば大丈夫です。

== Dockerfileを作成する

Dockerfileを作成する一番大きな理由ですが、簡単に言ってしまうと、TeX Liveはデフォルトでインストールされていないため、それをサポートするために必要になるからです。というわけで、さくっと作成しましょう。

//listnum[dockerfile][Dockerfile][Dockerfile]{
FROM ubuntu:18.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y texlive-full fonts-ipaexfont fonts-ipafont
RUN gem install bundler review math_ml
RUN kanji-config-updmap-sys ipaex
COPY entrypoint.sh /
RUN chmod a+x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
//}

なぜか4行目完了時にRubyがインストール済みになっているため、5行目では、いきなりgemをインストールしています。Rubyのバージョンは2.5.1なので、必要であればrbenv・ruby-build経由でインストールしてもよいですが、その場合、entrypoint.shではRubyのバージョン指定を行う必要があります。なお、今回はIPAexフォントを用いる設定にしていますが、IPAフォントを使いたい場合は、6行目の指定をipaに変更すれば大丈夫です。

== 説明用のREADMEを作成する

必要であれば、説明用のREADME.mdを作成します。と言っても、単なるREADMEなので、何も考えないで大丈夫です。

== GitHubレポジトリにpushする

ここまで準備ができたら、GitHubにレポジトリを作って、そこにpushします。今回のここまでのソースは@<href>{https://github.com/mh35/review_action}にあります。ぜひご活用ください。