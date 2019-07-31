#include "%{APPNAMELC}.h"

// KF
#include <KLocalizedString>
#include <QDebug>

%{APPNAME}::%{APPNAME}(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args)
{
    setObjectName(QStringLiteral("%{APPNAME}"));
}

void %{APPNAME}::init() {
    reloadConfiguration();
    connect(this, SIGNAL(prepare()), this, SLOT(prepareForMatchSession()));
    connect(this, SIGNAL(teardown()), this, SLOT(matchSessionFinished()));
}

void %{APPNAME}::prepareForMatchSession()
{
}

void %{APPNAME}::matchSessionFinished()
{
}

%{APPNAME}::~%{APPNAME}()
{
}

void %{APPNAME}::reloadConfiguration() {
    QList<Plasma::RunnerSyntax> syntaxes;
    syntaxes.append(Plasma::RunnerSyntax("query", "Explain query"));
    setSyntaxes(syntaxes);
}

void %{APPNAME}::match(Plasma::RunnerContext &context)
{
    if(!context.isValid()) return;
    const QString term = context.query();
    if (term.length() < 3) {
        return;
    }
    QList<Plasma::QueryMatch> matches;

    Plasma::QueryMatch match(this);
    match.setIconName("kdeapp");
    match.setText("Hello World!");
    matches.append(match);
    
    context.addMatches(matches);
}

void %{APPNAME}::run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match)
{
    Q_UNUSED(context)
    Q_UNUSED(match)

    // TODO
}

K_EXPORT_PLASMA_RUNNER(%{APPNAMELC}, %{APPNAME})

// needed for the QObject subclass declared as part of K_EXPORT_PLASMA_RUNNER
#include "%{APPNAMELC}.moc"
