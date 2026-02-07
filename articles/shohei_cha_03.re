= 第三章　リジェクトと鎌倉大仏

== 飽和市場

二月。

翔はApp Storeのガイドラインを読んでいた。

チュートリアルヘルを抜け出すため、翔が選んだ戦略は「Todoアプリをリリースする」だった。自分で作った唯一のオリジナルアプリ。機能は最小限だが、CRUD操作は動く。UIもデザイナーとして最低限の品質は確保した。データの永続化も、Swiftful Thinkingの動画を参考に@<code>{UserDefaults}で実装した。

Apple Developer Programに年間一万二千八百円を支払い、開発者アカウントを取得した。App Store Connectにログインし、アプリ情報を入力していく。アプリ名、説明文、スクリーンショット、カテゴリ——デザイナーとしての経験が活きる作業だった。スクリーンショットはFigmaで美しいモックアップに仕上げた。

そして、いざ審査に提出しようとした段階で、翔は検索した。「Todoアプリ　App Store　リリース」。

検索結果を読んで、血の気が引いた。

App Storeには、Todoアプリが@<b>{数万本}以上存在する。Apple純正の「リマインダー」アプリがプリインストールされている時点で、シンプルなTodoアプリはApp Storeの審査で@<b>{4.2 Design: Minimum Functionality}に引っかかる可能性が極めて高い。

//note[App Store審査ガイドライン 4.2]{
@<b>{4.2 Minimum Functionality}は、App Store Review Guidelinesの中でも頻繁に適用されるリジェクト理由の一つ。

@<b>{概要}：アプリには、Webサイトのリパッケージや単純なテンプレートアプリを超える、十分な機能と価値が求められる。

@<b>{よくあるリジェクト例}：
 * 既存のApple純正アプリ（リマインダー、時計、天気など）と機能が重複し、独自の付加価値がないアプリ
 * Webサイトの情報をそのまま表示するだけのアプリ
 * テンプレートから大幅な変更なく生成されたアプリ

@<b>{対策}：Webや既存アプリでは得られない@<b>{独自の体験や機能}を提供すること。位置情報、カメラ、センサーなどのネイティブ機能の活用が有効。
//}

翔はApp Store Connectの画面を閉じた。

五ヶ月間の学習。チュートリアルの写経。自力で作ったTodoアプリ。そのすべてが、App Storeの審査基準という巨大な壁の前で無力だった。

「新しいアプリを、作るしかない」

翔はそう結論づけた。しかし、チュートリアルヘルの只中にいる自分が、ゼロから新しいアプリを設計・実装できるのか。白紙のXcodeプロジェクトの前で固まった記憶が蘇る。

その夜、翔はスマートフォンのメモ帳を開いた。数週間前に書き留めた、あの単語が目に入った。

@<b>{Cursor。}


== AIという名の教師

Cursorのイベントは、渋谷のスタートアップオフィスで開催された。

翔がXでブックマークしたツイートのスレッドを辿ると、Connpassにイベントページがあった。「Cursor Meetup Tokyo #3 — AIコードエディタで変わる開発体験」。定員五十名、参加費無料。

会場に入ると、翔は違和感を覚えた。CA.swiftのLT会とは雰囲気が異なる。参加者の半数以上がMacではなくWindowsのノートPCを使っている。iOSエンジニアだけでなく、Web開発者、データサイエンティスト、デザイナーまで、多様なバックグラウンドの人々が集まっている。

イベントが始まった。登壇者がCursorの画面を大きなモニターに映す。

見た目はVisual Studio Codeにそっくりだった。左側にファイルツリー、中央にコードエディタ、下部にターミナル。翔がXcodeで見慣れたIDEのレイアウトと同じだ。

しかし、登壇者がショートカットキーを押すと、画面の右側にチャットウィンドウが開いた。そこにテキストを入力すると——

AIが、コードを書き始めた。

「このReactコンポーネントにダークモード対応を追加して」という一文だけで、AIが該当するファイルを特定し、必要な変更を提案し、差分をハイライト表示する。登壇者が「Accept」をクリックすると、コードが即座に反映された。

翔は目を見開いた。

次のデモ。登壇者がコードの一部を選択し、「この関数が何をしているか説明して」と入力する。AIが、そのコードの動作を日本語で丁寧に解説した。変数の役割、制御フローの流れ、返り値の意味——まるで隣に座った先輩エンジニアが教えてくれるかのように。

「これだ」

翔は心の中で叫んだ。

チュートリアルヘルの本質は「質問できる相手がいない」ことだった。志村さんはXでアドバイスをくれるが、リアルタイムでコードを見ながら教えてもらうのは難しい。村田さんのもくもく会は月に一度。Swiftful ThinkingのNickは一方通行の動画だ。

Cursorは、二十四時間いつでも質問に答えてくれるAIの先生だった。

//note[AIコードエディタとは]{
AIコードエディタは、大規模言語モデル（LLM）を統合したコードエディタ。代表的なものにCursorやGitHub Copilotがある。

@<b>{主な機能}：
 * @<b>{コード補完}：入力中のコードの続きをAIが予測・提案する
 * @<b>{チャット}：自然言語でコードについて質問したり、生成を依頼できる
 * @<b>{コードベース理解}：プロジェクト全体のファイル構成やコードの関連性をAIが理解した上で回答する
 * @<b>{リファクタリング}：既存のコードの改善案をAIが提示する
 * @<b>{デバッグ支援}：エラーメッセージを貼り付けると、原因と解決策を教えてくれる

翔にとって重要だったのは「質問できる」という点だ。チュートリアルでは得られない「なぜそうなるのか」「自分のコードのどこが間違っているのか」を、リアルタイムで聞ける。
//}

イベントの帰り道、翔はMac App StoreからCursorをダウンロードした。


== 一行の魔法

Cursorをインストールした翌日、翔はもう一つのツールを試してみることにした。

Xのタイムラインで話題になっていた@<b>{Claude Code}——ターミナル上で動作するAIコーディングエージェント。Cursorがエディタ内のAIアシスタントなら、Claude Codeはターミナルから直接コードを生成・編集するツールだ。

翔はClaude Codeをインストールし、空のSwiftUIプロジェクトを作成した。そしてターミナルに、こう入力した。

//quote{
SwiftUIでポモドーロタイマーアプリを作ってください。25分のタイマー、5分の休憩、タイマーの開始・停止・リセット機能を実装してください。
//}

Claude Codeが動き始めた。

ファイルが自動的に作成されていく。@<code>{TimerView.swift}、@<code>{TimerViewModel.swift}、@<code>{ContentView.swift}。コードが生成され、ファイルに書き込まれていく。翔はターミナルのログを見守った。

三分後。

「完了しました」とClaude Codeが告げた。

翔はXcodeでプロジェクトを開いた。ビルドボタンを押す。

@<b>{動いた。}

シミュレータに、ポモドーロタイマーが表示されている。円形のプログレスバーが中央にあり、残り時間がデジタル表示されている。「Start」ボタンを押すとカウントダウンが始まり、二十五分後に通知が鳴る設定になっている。UIもそれなりに整っている。

翔はしばらく、その画面を見つめていた。

たった一行のプロンプトで、アプリが完成した。自分が五ヶ月かけて学んできたSwiftUIの知識——@<code>{@State}、@<code>{Timer}、@<code>{ProgressView}、@<code>{NavigationStack}——それらを組み合わせたアプリが、三分で出来上がった。

感動と、そして微かな恐怖を感じた。

もしAIがこのスピードでアプリを作れるなら、自分が学んでいることに意味はあるのか？

翔はそのポモドーロタイマーのコードを読んでみた。@<code>{Timer.publish}で一秒ごとにイベントを発火し、@<code>{.onReceive}でカウントダウンを制御している。@<code>{withAnimation}でプログレスバーがなめらかに動く。コードとしては正しい。しかし——

翔はこのコードを、@<b>{理解していない}。

Claude Codeが生成したコードの中に、翔が知らないAPIがいくつもあった。@<code>{Timer.publish}、@<code>{.onReceive}、@<code>{RunLoop.main}。これらが何をしているのか、翔には説明できない。

「速すぎる」

翔は呟いた。AIにアプリを作ってもらうことは、チュートリアルの写経よりもさらにタチが悪い。チュートリアルの写経は、少なくとも自分の手でコードを打ち込む。AIに丸投げすると、自分の手には何も残らない。

翔は方針を決めた。

@<b>{AIは「答えを与えるツール」ではなく、「先生」として使う。}

Claude Codeでアプリを丸ごと生成するのではなく、Cursorで@<b>{対話しながら}コードを書く。わからないことがあればCursorに質問し、説明を受け、理解した上で自分の手でコードを書く。AIは教師であり、自分が生徒だ。教師に宿題をやらせてはいけない。

翔はCursorを開き、チャットウィンドウに最初の質問を打ち込んだ。

//quote{
SwiftUIで地図アプリを作りたいのですが、Swiftful Thinkingのチュートリアルで作ったローマの観光地アプリをベースに、日本の鎌倉の寺社仏閣を紹介するアプリに改変したいです。何から始めればいいですか？
//}


== ローマから鎌倉へ

Cursorの回答は明快だった。

//quote{
素晴らしいアイデアですね。ローマの観光地アプリを鎌倉の寺社仏閣アプリに改変するには、以下のステップで進めましょう。

1. Locationデータモデルの修正（鎌倉のスポットに合わせたカテゴリ追加）
2. LocationsDataServiceのデータを鎌倉の寺社仏閣に変更
3. カスタムAnnotation（ピン）を寺・神社・大仏で分ける
4. 画像アセットの追加
5. 多言語対応（日本語・英語）

まずはLocationモデルにカテゴリを追加しましょう。
//}

翔はCursorの提案に従い、まずデータモデルから手をつけた。Swiftful Thinkingのチュートリアルでは、場所のカテゴリは存在しなかった。しかし鎌倉には寺、神社、そして大仏がある。これらを区別するために、@<code>{enum}を使う。

「enumってどういうときに使うんですか？」と翔はCursorに聞いた。

//quote{
enumは「列挙型」と呼ばれ、決まった選択肢の中から一つを選ぶときに使います。例えば信号の色は「赤・黄・青」の三つだけですよね。これをenumで表現します。鎌倉の場所のカテゴリなら「寺・神社・大仏」の三つです。
//}

翔はCursorの説明を聞きながら、自分の手でコードを書いた。

//list[location_category][LocationCategory：場所のカテゴリ][swift]{
enum LocationCategory: String, CaseIterable {
    case temple = "寺"
    case shrine = "神社"
    case buddha = "大仏"

    // カテゴリごとに異なるピンアイコンを返す
    var pinImageName: String {
        switch self {
        case .temple:
            return "temple-pin"
        case .shrine:
            return "shrine-pin"
        case .buddha:
            return "buddha-pin"
        }
    }
}
//}

@<code>{CaseIterable}プロトコルに準拠させることで、@<code>{LocationCategory.allCases}ですべてのケースを配列として取得できる。フィルター機能を実装するときに便利だとCursorが教えてくれた。

次にLocationモデル。チュートリアルのシンプルな構造体に、カテゴリと多言語対応を追加する。

//list[location_model_kamakura][鎌倉アプリのLocationモデル][swift]{
// 多言語対応のための構造体
struct LocalizedString {
    let japanese: String
    let english: String

    func localized(for language: String) -> String {
        language == "en" ? english : japanese
    }
}

struct Location: Identifiable, Equatable {
    let name: LocalizedString
    let cityName: LocalizedString
    let coordinates: CLLocationCoordinate2D
    let description: LocalizedString
    let imageNames: [String]
    let link: LocalizedLinks
    let category: LocationCategory

    var id: String {
        name.japanese + cityName.japanese
    }

    // Equatable
    static func == (lhs: Location, rhs: Location) -> Bool {
        lhs.id == rhs.id
    }
}
//}

「@<code>{LocalizedString}って、自分で作っていいんですか？」と翔はCursorに聞いた。

//quote{
はい。Swiftでは独自の型を自由に作れます。LocalizedStringは「日本語と英語のペア」を保持する小さな構造体です。これにより、アプリ内の文字列をすべて多言語対応できます。Appleの標準ローカライズ機構（Localizable.strings）を使う方法もありますが、データ駆動のアプリではこのアプローチも有効です。
//}

翔はCursorに質問しては理解し、理解しては自分で書く、というサイクルを繰り返した。Claude Codeのように一発でアプリを生成するのではなく、一行ずつ、対話しながら進める。時間はかかる。しかし、一行ごとに「なぜこう書くのか」を理解できる。

これが、翔にとっての@<b>{AIを先生として使う}ということだった。


== 十七のピン

Locationモデルとカテゴリのenumが完成した。次はデータだ。

翔は鎌倉に行ったことがあった。大学時代、友人と日帰りで訪れた記憶がある。鶴岡八幡宮の大階段、小町通りの食べ歩き、大仏の圧倒的な存在感。しかしそのとき翔はカメラでスナップを撮っただけで、寺社仏閣の歴史や文化には興味がなかった。

今は違う。翔はアプリに掲載する寺社仏閣を選定するため、鎌倉の寺社について徹底的に調べた。Wikipediaを読み、公式サイトを訪問し、Google Mapsで座標を確認する。そして週末、実際に鎌倉を訪れて写真を撮影した。

デザイナーの目で、寺社の美しさを切り取る。建長寺の総門の荘厳さ。明月院の丸窓から覗く庭園。報国寺の竹林に差し込む光。高徳院の大仏の静謐な表情。

翔はCursorの助けを借りながら、@<code>{LocationsDataService}にデータを入力していった。

//list[locations_data_service][LocationsDataService：鎌倉の寺社仏閣データ][swift]{
class LocationsDataService {

    static let locations: [Location] = [
        Location(
            name: LocalizedString(
                japanese: "鶴岡八幡宮",
                english: "Tsurugaoka Hachimangū"
            ),
            cityName: LocalizedString(
                japanese: "雪ノ下",
                english: "Yukinoshita"
            ),
            coordinates: CLLocationCoordinate2D(
                latitude: 35.3258,
                longitude: 139.5564
            ),
            description: LocalizedString(
                japanese: "鶴岡八幡宮は、神奈川県鎌倉市雪ノ下にある神社。"
                    + "武家源氏、鎌倉武士の守護神。"
                    + "鎌倉初代将軍源頼朝ゆかりの神社として知られる。",
                english: "Tsurugaoka Hachimangū is a Shinto shrine "
                    + "located in Yukinoshita, Kamakura."
            ),
            imageNames: [
                "tsurugaoka-hachimangu-1",
                "tsurugaoka-hachimangu-2",
                "tsurugaoka-hachimangu-3",
            ],
            link: LocalizedLinks(
                japanese: "https://ja.wikipedia.org/wiki/鶴岡八幡宮",
                english: "https://en.wikipedia.org/wiki/Tsurugaoka_Hachimangū"
            ),
            category: .shrine
        ),
        Location(
            name: LocalizedString(
                japanese: "建長寺",
                english: "Kenchō-ji"
            ),
            cityName: LocalizedString(
                japanese: "山ノ内",
                english: "Yamanouchi"
            ),
            coordinates: CLLocationCoordinate2D(
                latitude: 35.3333,
                longitude: 139.5529
            ),
            description: LocalizedString(
                japanese: "建長寺は、鎌倉五山の第一位に列せられる"
                    + "臨済宗建長寺派の大本山。"
                    + "境内は国の史跡に指定されている。",
                english: "Kenchō-ji ranks first among the "
                    + "Five Great Zen Temples of Kamakura."
            ),
            imageNames: [
                "kenchoji-1",
                "kenchoji-2",
                "kenchoji-3",
            ],
            link: LocalizedLinks(
                japanese: "https://ja.wikipedia.org/wiki/建長寺",
                english: "https://en.wikipedia.org/wiki/Kenchō-ji"
            ),
            category: .temple
        ),
        // ... 長谷寺、円覚寺、高徳院（鎌倉大仏）、明月院、
        //     報国寺、東慶寺、浄智寺、銭洗弁財天、浄光明寺、
        //     海蔵寺、光明寺、寿福寺、安養院、荏柄天神社、
        //     本覚寺 ... 全17スポット
    ]
}
//}

十七箇所。鶴岡八幡宮、建長寺、長谷寺、円覚寺、高徳院、明月院、報国寺、東慶寺、浄智寺、銭洗弁財天宇賀福神社、浄光明寺、海蔵寺、光明寺、寿福寺、安養院、荏柄天神社、本覚寺。

寺が十二、神社が三、大仏が一。鎌倉五山（建長寺・円覚寺・寿福寺・浄智寺・浄光明寺）もすべて収録した。

各スポットに三枚ずつの写真。翔が実際に鎌倉で撮影した写真だ。デザイナーとしての構図感覚を活かし、建物の正面、ディテール、雰囲気の三種類を撮り分けた。画像はXcodeのAssets.xcassetsに@<code>{imageset}として追加した。

そしてカスタムピンアイコン。翔はFigmaでSVGアイコンをデザインした。寺のアイコンは屋根の曲線を模した形、神社のアイコンは鳥居のシルエット、大仏のアイコンは仏像の輪郭。三種類のピンがカテゴリごとに地図上に表示される。

デザイナーとしてのスキルが、ここで決定的に活きた。エンジニアが作るアプリのアイコンとは、一線を画すクオリティ。翔は自分のバックグラウンドが「弱み」ではなく「強み」だと、改めて実感した。

シミュレータで鎌倉の地図を表示すると、十七のピンが鎌倉エリアに散りばめられた。寺は緑、神社は赤、大仏は金のアイコン。ピンをタップすると、プレビューカードがスライドして現れ、寺社の名前、所在地、写真が表示される。さらにタップすると詳細画面に遷移し、説明文とWikipediaへのリンクが表示される。

翔はシミュレータの画面をスクリーンショットに撮り、Xに投稿した。

//quote{
鎌倉の寺社仏閣マップアプリを開発中。Swiftful Thinkingのチュートリアルをベースに、17箇所の寺社をカテゴリ別ピンで表示。寺・神社・大仏でアイコンを変えてます。デザイナーの経験がアイコン制作で活きた。#SwiftUI #MapKit #BuildInPublic
//}


== 最初のリジェクト

三月上旬。

翔は鎌倉地図アプリ「Kamakura Temple」をApp Store Connectにアップロードした。

アプリ名、サブタイトル、説明文、キーワード、スクリーンショット——すべてをデザイナーとしてのスキルを活かして丁寧に仕上げた。プライバシーポリシーのURLも用意した。Cursorに聞きながら、App Transport Security、Info.plistの設定も確認した。

「Submit for Review」ボタンを押す。

審査中。

翔はXcodeを閉じ、深呼吸した。Appleの審査は通常一日から三日程度で結果が出るという。

三日後。

メールが届いた。

差出人：Apple。件名：@<b>{Your submission was rejected}。

翔の心臓が凍りついた。

メールを開く。

//quote{
Guideline 4.2 - Design - Minimum Functionality

We found that the usefulness of your app is limited by the minimal amount of content or features it includes.

Specifically, your app provides a limited user experience as it is not sufficiently different from a mobile web browsing experience.
//}

@<b>{4.2 Minimum Functionality。}

Todoアプリでリリースを断念したとき、翔が恐れていたあのガイドラインだ。

「Webで検索するのと変わらない機能しかない」——つまり、鎌倉の寺社仏閣の情報を地図上に表示するだけなら、Google Mapsで検索すれば同じことができる。App Storeに並べる価値がない、とAppleは判断した。

翔はMacBook Airの前で、数分間、動けなかった。

五ヶ月以上の学習。鎌倉への取材旅行。十七箇所のデータ入力。カスタムアイコンのデザイン。多言語対応の実装。そのすべてが「不十分」と判定された。

しかし、翔は気づいていた。Appleの指摘は正しい。このアプリには「Webでは得られない独自の体験」が欠けている。地図に情報を表示するだけなら、確かにWebで十分だ。

翔はリジェクトの通知画面を閉じず、もう一度読み返した。

「not sufficiently different from a mobile web browsing experience」。

ネイティブアプリでしかできないこと。Webにはない価値。

翔はそのヒントを握りしめたまま、次の一手を探し始めた。


== エヴァンジェリストの助言

リジェクトの翌週、翔はConnpassで「Apple Technology Day」というイベントを見つけた。

Appleが定期的に開催するエンジニア向けのイベントで、Appleのエヴァンジェリストやエンジニアが参加者の質問に直接答えてくれるという。翔は迷わず参加登録した。

会場はAppleの日本法人が入るビル。受付を済ませると、広いイベントスペースにテーブルが並び、Appleのスタッフが各テーブルで開発者の相談を受けている。

翔は一人のスタッフの前に座った。名札には「石武」と書かれている。Appleのデベロッパーリレーションズのエヴァンジェリストだった。

「あの、App Store審査で4.2 Minimum Functionalityでリジェクトされたんですが——」

翔は事情を説明した。鎌倉の寺社仏閣の地図アプリ。十七箇所のスポット。カテゴリ別のカスタムピン。多言語対応。しかし「Webで検索するのと変わらない」と判定された。

石武さんは穏やかに頷きながら聞いていた。

「なるほど。4.2はよくあるリジェクト理由ですね。まず、リジェクトされたとき、App Store Connectの画面からAppleに問い合わせができるのは知っていますか？」

翔は首を横に振った。

「Resolution Centerというページがあって、そこからAppleの審査チームに直接メッセージを送れます。なぜリジェクトなのか、具体的にどう改善すればいいのか、質問できるんです。多くの開発者がこれを知らずに、推測で修正しているんですが、直接聞いた方が確実です」

//note[App Store審査リジェクトへの対応]{
App Store審査でリジェクトされた場合の対応方法：

@<b>{1. Resolution Center}
App Store Connectのリジェクト通知画面から、Appleの審査チームに直接メッセージを送れる。リジェクト理由の詳細な説明を求めたり、改善案について相談できる。

@<b>{2. App Review Board}
Resolution Centerでの回答に納得できない場合、上位の審査ボードに再審査を依頼できる。

@<b>{3. 改善のポイント}
 * リジェクト理由を正確に理解する（推測で修正しない）
 * 「Webでは得られない独自の体験」を追加する
 * 位置情報、カメラ、プッシュ通知などのネイティブ機能の活用が有効
 * 改善点を審査チームに明確に伝える
//}

石武さんは続けた。

「それから、4.2の対策としては、@<b>{ネイティブアプリならではの体験}を入れることです。例えば、位置情報を使ったユーザー体験。ユーザーが実際にその場所にいるときだけ使える機能とか」

位置情報を使ったユーザー体験。

翔の頭の中で、何かが繋がった。

「例えば……今自分がいる場所にコメントを残せる機能、とかはどうですか？」

石武さんは微笑んだ。

「いいアイデアですね。それはWebではできない、GPSを使ったネイティブな体験です。実際にその場所に行った人だけがコメントを残せるなら、他の地図アプリにはない独自の価値になります」

翔はイベント会場を出ると、走るようにして最寄りのカフェに入った。MacBook Airを開き、Cursorを起動する。チャットウィンドウに入力した。

//quote{
鎌倉地図アプリに「現在地にコメントを残す」機能を追加したいです。ユーザーが実際にその場所にいるときに、テキストコメントを投稿できて、地図上にコメントのピンが表示される仕組みにしたいです。どう実装すればいいですか？
//}


== コメントという翼

Cursorとの対話が始まった。

まず、コメントのデータモデルを設計する。コメントには何が必要か。テキスト、座標、タイムスタンプ、ユーザー情報。Cursorに相談しながら、翔は@<code>{Comment}構造体を書いた。

//list[comment_model][Comment：コメントのデータモデル][swift]{
struct Comment: Identifiable, Codable, Equatable {
    let id: UUID
    let text: String
    let coordinate: CLLocationCoordinate2D
    let timestamp: Date
    let userId: String
    let userName: String

    init(
        text: String,
        coordinate: CLLocationCoordinate2D,
        userId: String = "user",
        userName: String = "ユーザー"
    ) {
        self.id = UUID()
        self.text = text
        self.coordinate = coordinate
        self.timestamp = Date()
        self.userId = userId
        self.userName = userName
    }
}
//}

ここで翔は壁にぶつかった。@<code>{CLLocationCoordinate2D}は@<code>{Codable}に準拠していない。つまり、そのままではJSONにエンコード・デコードできず、データの保存ができない。

「@<code>{CLLocationCoordinate2D}が@<code>{Codable}じゃないんですが、どうすればいいですか？」とCursorに聞いた。

//quote{
CLLocationCoordinate2Dは構造体ですが、Codableに準拠していません。自分でCodingKeysを定義し、latitudeとlongitudeを個別にエンコード・デコードする方法が一般的です。
//}

Cursorの説明に従い、翔は@<code>{CodingKeys}とカスタムの@<code>{encode}/decode}メソッドを実装した。

//list[comment_codable][CommentのCodable対応][swift]{
// CLLocationCoordinate2DのCodable対応
enum CodingKeys: String, CodingKey {
    case id, text, latitude, longitude,
         timestamp, userId, userName
}

init(from decoder: Decoder) throws {
    let container = try decoder.container(
        keyedBy: CodingKeys.self
    )
    id = try container.decode(UUID.self, forKey: .id)
    text = try container.decode(String.self, forKey: .text)
    let latitude = try container.decode(
        Double.self, forKey: .latitude
    )
    let longitude = try container.decode(
        Double.self, forKey: .longitude
    )
    coordinate = CLLocationCoordinate2D(
        latitude: latitude, longitude: longitude
    )
    timestamp = try container.decode(
        Date.self, forKey: .timestamp
    )
    userId = try container.decode(
        String.self, forKey: .userId
    )
    userName = try container.decode(
        String.self, forKey: .userName
    )
}

func encode(to encoder: Encoder) throws {
    var container = encoder.container(
        keyedBy: CodingKeys.self
    )
    try container.encode(id, forKey: .id)
    try container.encode(text, forKey: .text)
    try container.encode(
        coordinate.latitude, forKey: .latitude
    )
    try container.encode(
        coordinate.longitude, forKey: .longitude
    )
    try container.encode(timestamp, forKey: .timestamp)
    try container.encode(userId, forKey: .userId)
    try container.encode(userName, forKey: .userName)
}
//}

@<code>{CLLocationCoordinate2D}をそのままエンコードするのではなく、@<code>{latitude}と@<code>{longitude}を@<code>{Double}として個別に保存する。デコード時にはその二つの@<code>{Double}から@<code>{CLLocationCoordinate2D}を再構築する。

翔はこのコードを書きながら、@<code>{Codable}プロトコルの仕組みを深く理解した。Cursorに質問し、説明を受け、自分で書く。このサイクルが、翔の学習を加速させていた。

次に、コメントの投稿画面と、地図上のコメント表示を実装する。@<code>{CLLocationManager}でユーザーの現在地を取得し、テキスト入力フィールドでコメントを書き、投稿ボタンを押すと地図上にコメントのピンが追加される。

コメントデータは@<code>{UserDefaults}に保存する。@<code>{Codable}に対応したおかげで、@<code>{JSONEncoder}でData型に変換し、@<code>{UserDefaults}に書き込むことができた。

一週間の実装期間。Cursorとの対話は数百回に及んだ。しかし、すべてのコードは翔が自分の手で書いた。AIが生成したコードをコピー＆ペーストしたのではなく、AIに教わりながら、一行ずつ理解して書いた。


== 再申請

三月下旬。

翔はコメント機能を追加した「Kamakura Temple」の新バージョンをApp Store Connectにアップロードした。

審査チームへのメモ欄に、翔は以下を記載した。

//quote{
前回の審査で4.2 Minimum Functionalityのフィードバックをいただきました。改善点として、ユーザーが現在地にコメントを残せる機能を追加しました。この機能はGPSを使用しており、実際にその場所を訪れたユーザーのみがコメントを投稿できます。Webブラウザでは実現できない、ネイティブアプリならではの体験を提供しています。
//}

Resolution Centerで審査チームに丁寧に説明することの重要性を、石武さんに教わっていた。なぜこの変更を行ったのか、この機能がなぜWebでは実現できないのか、明確に伝える。

「Submit for Review」。

待つ。

一日目。通知なし。

二日目。通知なし。翔はXcodeを開いては閉じ、App Store Connectのステータスを何度も確認した。「In Review」の文字が変わらない。

三日目の朝。

メールが来た。

差出人：Apple。

翔は目を閉じ、深呼吸してから開いた。

//quote{
Your submission has been approved.
//}

承認。

//note[App Store Connectでのリリースフロー]{
iOSアプリをApp Storeにリリースするまでの主なステップ：

@<b>{1. Apple Developer Program登録}：年間12,800円。開発者アカウントの取得。

@<b>{2. アプリ情報の設定}：App Store Connectでアプリ名、説明文、キーワード、カテゴリ、年齢制限、スクリーンショットを設定。

@<b>{3. ビルドのアップロード}：Xcodeから「Archive」でビルドし、App Store Connectにアップロード。

@<b>{4. 審査提出}：「Submit for Review」で審査に提出。通常1〜3日で結果が出る。

@<b>{5. 審査通過後}：手動リリースか自動リリースを選択。自動なら審査通過後すぐにApp Storeに公開される。

翔のアプリは最初のバージョンがリジェクトされ、コメント機能を追加した二回目の提出で承認された。リジェクトは失敗ではなく、アプリを改善するためのフィードバックだ。
//}

翔はApp Storeを開いた。検索バーに「Kamakura Temple」と入力する。

あった。

自分のアプリが、App Storeに並んでいる。自分がデザインした寺のアイコン。自分が撮影した鶴岡八幡宮のスクリーンショット。自分が書いた説明文。自分が一行ずつコードを書いたアプリ。

翔の目に涙が滲んだ。

デザイン会社のアシスタントとして、上司の指示で色味を調整していたあの日々。自分の名前が載らないデザインデータを量産していたあの夜。「これでいいのか」と自問自答していたあの午前一時。

今、App Storeに、翔の名前が載っている。

@<b>{Developer: Shohei Yukikawa}

自分の名前で、自分の作品が、世界に公開された。


== App Storeの星空

翌朝、翔のiPhoneに通知が届いた。

@<b>{App Store Connect: 1 download}

誰かが、翔のアプリをダウンロードした。

見知らぬ誰かが、App Storeで「Kamakura Temple」を見つけ、スクリーンショットを見て、ダウンロードボタンを押した。その人のiPhoneに、翔が書いたコードが動いている。翔がデザインしたピンアイコンが、鎌倉の地図上に表示されている。

翔はしばらく、通知画面を見つめていた。

一ダウンロード。数字としては微々たるものだ。しかし、その一ダウンロードは、翔にとって、デザイン会社で作ったどんなパンフレットよりも重い意味を持っていた。

翌週の村田さんのもくもく会。翔はApp Storeの画面をみんなに見せた。

「リリースできたんですね！　おめでとうございます！」

村田さんが手を叩いた。他の参加者からも拍手が起きた。

「一回リジェクトされたんですけど、コメント機能を追加して再申請したら通りました」

「リジェクト対応してリリースまで持っていったのは偉いですよ。多くの人が一回リジェクトされたらそこで諦めるんで」

翔はXにも投稿した。

//quote{
App Storeにアプリをリリースしました！「Kamakura Temple」— 鎌倉の寺社仏閣マップアプリです。17箇所の寺・神社・大仏をカテゴリ別ピンで表示。現在地にコメントを残せるオリジナル機能付き。一度リジェクトされましたが、改善して再申請して通りました。SwiftUI学習6ヶ月の成果です。#SwiftUI #AppStore #BuildInPublic #個人開発
//}

志村さんからリプライが来た。

//quote{
@yukikawa_sho リリースおめでとうございます！6ヶ月でここまで来たのは本当にすごい。しかもリジェクト対応も経験したのは大きい。実務でもApp Store審査とのやりとりは避けて通れないから、ここで経験できたのは財産ですよ。次のアプリも楽しみにしてます！
//}

中野からもDMが来た。

//quote{
翔くん、アプリリリースおめでとう！Ignoreのアイコン作ってくれたときは何もできなかったのに、半年で自分のアプリ出すとか成長早すぎない？笑
//}

翔は中野のメッセージを読み返した。半年前、コワーキングスペースでアイコンを作ることしかできなかった自分。XcodeもSwiftも知らなかった自分。

今、App Storeに自分のアプリが並んでいる。

翔はXcodeを開いた。次にやることは、もう決まっていた。

一つ目は、LT会で発表すること。CA.swiftで「いつかあのステージで発表する」と心に決めたあの夜。自分のアプリがある今なら、発表できるネタがある。リジェクトされて、改善して、リリースした体験談。初心者にも参考になるはずだ。

二つ目は、二つ目のアプリを作ること。Kamakura Templeは翔の最初のリリースアプリだが、チュートリアルのコードをベースにしている。次は、完全にゼロからオリジナルのアプリを作りたい。

翔はメモ帳を開いた。

@<b>{次にやること：}
 * LT会に登壇する
 * 二つ目のアプリを企画・開発・リリースする
 * もくもく会に継続参加する
 * 村田さんのカフェ営業を応援する

村田さんが最近、もくもく会の会場にしている下北沢のカフェスペースで「間借りカフェ」を始めたいと話していた。もくもく会の頻度は変わるかもしれない。しかし翔は、コミュニティとのつながりを大切にしたいと思っていた。

午前一時。

翔はApp Storeの「Kamakura Temple」のページを開いた。ダウンロード数は十二。レビューはまだゼロ。売上もゼロ。

しかし、その画面は翔にとって、星空のように見えた。十七のピンが鎌倉の地図に散りばめられている。一つ一つが、翔が調べ、撮影し、コードを書いた場所だ。

翔はMacBook Airを閉じた。六ヶ月前、このMacBook Airは冷たい光を放つだけの機械だった。今は、翔の作品を世界に届ける道具に変わった。

明日は、LT会の登壇申し込みをする。

翔はベッドに入り、目を閉じた。瞼の裏に、鎌倉大仏の穏やかな表情が浮かんだ。高徳院の境内で撮影した写真。コードの中では@<code>{CLLocationCoordinate2D(latitude: 35.3169, longitude: 139.5358)}という座標に過ぎないが、翔にとっては自分のアプリの、自分の旅の、記憶だった。
