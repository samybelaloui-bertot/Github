<?php
/* Smarty version 3.1.31, created on 2017-04-02 14:39:57
  from "C:\wamp\www\accueil.tpl" */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.31',
  'unifunc' => 'content_58e10d3d0b9623_59179558',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '46a66c6c7ec1d3e3db548a9389589442950b84d6' => 
    array (
      0 => 'C:\\wamp\\www\\accueil.tpl',
      1 => 1491143994,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:./header.tpl' => 1,
    'file:./footer.tpl' => 1,
  ),
),false)) {
function content_58e10d3d0b9623_59179558 (Smarty_Internal_Template $_smarty_tpl) {
if (!is_callable('smarty_function_connexion')) require_once 'C:\\wamp\\www\\smarty\\plugins\\function.connexion.php';
?>
<!DOCTYPE html>

<html lang="fr">
<head>
  <title> Acupuncteurs en médecine traditionnelle chinoise </title>
  <meta name="description" content="Acupuncteurs en médecine traditionnelle chinoise" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" media="screen" type="text/css" href="style.css" />

<?php $_smarty_tpl->_subTemplateRender('file:./header.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>


<body>
   <header>
   </header>

   <nav>
    <ul>
      <li> <a class="active" accesskey="1" href="index.php?page=accueil">Page d'accueil (1) </a> </li>
      <li> <a accesskey="2" href="index.php?page=categorie">Accès aux données (2)</a> </li>
      <li> <a accesskey="3" href="index.php?page=info">Page d'information (3) </a> </li>
      <li> <a accesskey="4" href="index.php?page=rss">RSS (4)</a> </li>
      <li id="connex" accesskey="5"> <?php echo smarty_function_connexion(array(),$_smarty_tpl);?>
 </li>
    </ul>
   </nav>
   <div class="gros_titre">
     <h1>ACUPUNCTURE</h1>

     <h2>Page d'accueil</h2>
   </div>


    <?php if (!isset($_SESSION['login'])) {?>
    <div class="formulaire_css">

      <h1>  Inscription </h1>
      <form method="post" action="inscription-source.php">
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
    <?php }?>

      <?php $_smarty_tpl->_subTemplateRender('file:./footer.tpl', $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array(), 0, false);
?>


  </body>
</html>
<?php }
}
