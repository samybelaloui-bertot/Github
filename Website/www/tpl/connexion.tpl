<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="../css/style.css" />

 <body>

    {include file='./header.tpl'}
    <header>
    </header>

    <nav>
     <ul>
       <li> <a accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
       <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
       <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
       <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
       <li class="active" id="connex" accesskey="5"> {connexion} </li>

     </ul>
    </nav>

    <div class="gros_titre">
      <h1>ACUPUNCTURE</h1>

      <h2>Connexion</h2>
    </div>

      <div class="formulaire_css">
        <h1>  Connexion </h1>

          <form method="post" action="index.php?page=connexion-source">       <!-- LIEN AVEC LA CIBLE PHP QUI RECOIT LES DONNES DU  FORMULAIRE -->
            <ul>
              <li>
                <label for="login">Login (L) &nbsp;:</label>
                <input type="text" id="login" name="login" placeholder="Dupont" required accesskey="L">
              </li>
              <li>
                <label for="password">Mot de passe (M) &nbsp;:</label>
                <input type="password" id="password" name="password" required accesskey="M">
              </li>
              <li>
              <input type="submit" value="Connexion" />
              </li>
            </ul>
          </form>
        </div>

    {include file='./footer.tpl'}
</body>

</html>
