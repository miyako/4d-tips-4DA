![version](https://img.shields.io/badge/version-19%2B-5682DF)
![platform](https://img.shields.io/static/v1?label=platform&message=mac-intel%20|%20mac-arm%20|%20win-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/4d-tips-4DA)](LICENSE)

## ユーザーフォーム

v2004では**ユーザーフォーム**が利用できるようになりました。ユーザーフォームは，テーブル入出力フォームをカスタマイズした派生フォームで，テーブル入出力フォームの代わりに使用したり，簡易版のフォームエディターで修正したりすることができます。

* [_o_CREATE USER FORM](https://doc.4d.com/4Dv19/4D/19.5/o-CREATE-USER-FORM.301-6136499.ja.html)

* [_o_EDIT FORM](https://doc.4d.com/4Dv19/4D/19.5/o-EDIT-FORM.301-6136464.ja.html)

* [FORM SET INPUT](https://doc.4d.com/4Dv19/4D/19.5/FORM-SET-INPUT.301-6136695.ja.html)

* [FORM SET OUTPUT](https://doc.4d.com/4Dv19/4D/19.5/FORM-SET-OUTPUT.301-6136701.ja.html)

**注記**: 過去バージョンのドキュメントは[livedoc.4d.com](https://livedoc.4d.com)または[library.4d-japan.com](https://library.4d-japan.com/REFERENCE/)で参照することができます。

* [ユーザフォームの概要](https://livedoc.4d.com/--14.4/-/-.300-2511952.ja.html)

ユーザーフォームの仕組みは，**v18で廃止予定**となりました。

## ダイナミックフォーム

v17では，入出力フォーム・ダイアログ・サブフォームにドキュメントのパスまたはオブジェクトが指定できるようになりました。そのようなフォームは，事前にフォームエディターで作成したものではなく，動的に構築されたものであるという意味で，ダイナミックフォームと呼ばれます。JSON形式でスキーマ定義されているためにJSONフォームと呼ばれることもあります。

* [ダイナミックフォーム](https://doc.4d.com/4Dv19/4D/19/Dynamic-Forms.300-5416668.ja.html)

v19では，デザインモードのフォームエディターを起動するコマンドが追加されました。

* [FORM EDIT](https://doc.4d.com/4Dv19/4D/19.5/FORM-EDIT.301-6137414.ja.html)

[_o_EDIT FORM](https://doc.4d.com/4Dv19/4D/19.5/o-EDIT-FORM.301-6136464.ja.html)とは違い，コンパイルされたアプリケーションで任意のフォームを開くことはできません。ダイナミックフォームは自由にフォームをカスタマイズできるという点ではユーザーフォームに代わるものですが，**フォームエディターのグラフィカルユーザーインタフェースを使用して視覚的にカスタマイズするというコンセプトは廃止**されたことに留意する必要があります。
