<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="../css/style.css" />

{include file='./header.tpl'}

<body>
   <header>
   </header>

   <nav>
    <ul>
      <li> <a class="active" accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
      <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
      <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
      <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
      <li id="connex" accesskey="5"> {connexion} </li>
    </ul>
   </nav>
   <div class="gros_titre">
     <h1>ACUPUNCTURE</h1>

     <h2>Page d'accueil</h2>
   </div>


    {if !isset($smarty.session.login)}
    <div class="formulaire_css">

      <h1>  Inscription </h1>
      <form method="post" action="../php/inscription-source.php">
      <ul>
        <li>
          <label for="login">Login (L)&nbsp;:</label>
          <input type="text" id="login" name="login" placeholder="Dupont" required accesskey="L" >
        </li>
        <li>
          <label for="email_addr">Adresse e-mail (A)&nbsp;:</label>
          <input type="email" id="email_addr" name="email_addr" required accesskey="A" >
        </li>
        <li>
          <label for="email_addr_repeat">Confirmez l adresse e-mail (C)&nbsp;:</label>
          <input type="email" id="email_addr_repeat" name="email_addr_repeat" required accesskey="C"
          oninput="check(this)">
        </li>
        <li>
          <label for="password">Mot de passe (M)&nbsp;:</label>
          <input type="password" id="password" name="password" required accesskey="M" >
        </li>
        <li>
          <label for="password_repeat">Confirmez le mot de passe (N)&nbsp;:</label>
          <input type="password" id="password_repeat" name="password_repeat" required accesskey="N"
          oninput="check(this)">
        </li>
        <li>
          <input type="submit" value="Confirmer l inscription" />
        </li>
      </ul>
      </form>
    </div>
    {/if}

      {include file='./footer.tpl'}

  </body>
</html>
