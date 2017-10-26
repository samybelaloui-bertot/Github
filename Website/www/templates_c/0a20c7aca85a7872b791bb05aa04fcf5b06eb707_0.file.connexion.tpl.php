<?php
/* Smarty version 3.1.31, created on 2017-04-02 15:22:46
  from "C:\wamp64\www\connexion.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58e11746bd3db6_21824723',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '0a20c7aca85a7872b791bb05aa04fcf5b06eb707' => 
    array (
      0 => 'C:\\wamp64\\www\\connexion.tpl',
      1 => 1491144176,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:./header.tpl' => 1,
    'file:./footer.tpl' => 1,
  ),
),false)) {
function content_58e11746bd3db6_21824723 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp64\\www\\smarty\\plugins\\function.connexion.php';
?>
<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="style.css" />

 <body>

    <?php $_smarty_tpl->_subTemplateRender('file:./header.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

    <header>
    </header>

    <nav>
     <ul>
       <li> <a accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
       <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
       <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
       <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
       <li class="active" id="connex" accesskey="5"> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>

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

    <?php $_smarty_tpl->_subTemplateRender('file:./footer.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>

</body>

</html>
<?php }
}
